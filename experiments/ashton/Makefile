all: main

main: main.o
	g++ main.o -o main -lm -lX11 -pthread -lsfml-window -lsfml-graphics -lsfml-system

main.o: main.cpp
	g++ -c -Werror -g main.cpp -o main.o -lm

clean:
	rm -f main *~ *.o
