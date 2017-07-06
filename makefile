SRC = $(wildcard src/*.cpp)
lflag = -framework cocoa -framework SDL2 -framework SDL2_image

all:
	g++ $(SRC) -o chess $(lflag) -std=c++11

