all:
	g++ -Wall -c -std=c++11 *.cpp
	g++ -framework SDL2 -framework SDL2_image *.o -o main