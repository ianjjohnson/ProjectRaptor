OBJS = *.cpp
CC = g++
COMPILER_FLAGS = -w
LINKER_FLAPGS = -lSDL2 -lSDL2_image
OBJ_NAME = main

mac:
	g++ -Wall -c -std=c++11 *.cpp
	g++ -framework SDL2 -framework SDL2_image *.o -o main
linux:
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAPGS) -o $(OBJ_NAME)
