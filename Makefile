all:
	g++ -Isrc/Include -Lsrc/lib -o main main.cpp Game.cpp TextureManager.cpp GameObject.cpp Map.cpp Vector2D.cpp Collision.cpp -lmingw32 -lSDL2main -lSDL2_image -lSDL2