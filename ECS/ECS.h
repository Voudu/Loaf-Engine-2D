#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

/*
*   ECS - Entity Component System
*
*   This whole ECS stuff is used for keeping a list of the entities in the world and updating or destroying them as necessary. We use the
*   Manager class to control this behavior.
*   The complexity seen here is to maintain cache efficiency and is wildly complex to me. If we need to understand more or go back to reference where
*   I got this code from, see the youtube link below.
*  
*   For now, we know it is the component and entity system
*
*   https://www.youtube.com/watch?v=XsvI8Sng6dk&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=9&ab_channel=Let%27sMakeGames
*/


class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
    static ComponentID typeID = getComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component {

public:
    Entity* entity;

    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}

    virtual  ~Component() {}
};

class Entity {

public:
    void update()
    {
        for(auto& c : components) c->update();
    }
    
    void draw() 
    {
        for(auto& c : components) c->draw();
    }

    bool isActive() const { return active; }
    void destroy() { active = false; }

    template <typename T> bool hasComponent() const
    {
        return componentBitset[getComponentTypeID<T>()];
    }

    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{ c };
        components.emplace_back(std::move(uPtr));

        componentArray[getComponentTypeID<T>()] = c;
        componentBitset[getComponentTypeID<T>()] = true;

        c->init();
        return *c;
    }

    template <typename T> T& getComponent() const
    {
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }

private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;
    
    ComponentArray componentArray;
    ComponentBitSet componentBitset;

};

class Manager
{
public:
    void update()
    {
        for (auto& e : entities) e->update();
    }

    void draw()
    {
        for (auto& e : entities) e->draw();
    }

    void refresh()
    {
        // remove entities if they're not active
        entities.erase( std::remove_if(std::begin(entities), std::end(entities),
             [](const std::unique_ptr<Entity> &mEntity)
        {
            return !mEntity->isActive();
        }),
        std::end(entities));
    }

    Entity& addEntity()
    {
        Entity* e = new Entity();
        std::unique_ptr<Entity> uPtr{ e };
        entities.emplace_back(std::move(uPtr));

        return *e;
    }

private:
    std::vector<std::unique_ptr<Entity>> entities;

};