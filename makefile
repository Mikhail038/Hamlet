CXX_FLAGS = -Wall -Wextra -fsanitize=address -g -ggdb3

all: hamlet

main.o: main.cpp
	g++ -c -o main.o main.cpp 

core.o: core.cpp
	g++ -c -o core.o core.cpp 

hamlet: main.o core.o
	g++ main.o core.o $(CXX_FLAGS) -o Hamlet.out 

