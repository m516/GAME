all: main

main: main.o
	g++ main.o -o main -lm -lsfml-window -lsfml-graphics -lsfml-system

main.o: main.cpp
	g++ -c -Wall -Werror -g main.cpp -o main.o -lm

clean:
	rm -f main *~ *.o
