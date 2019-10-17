all: main

# Compile and link main.o into executable main
main: main.o
	g++ main.o -o main -lm -lX11 -pthread -lsfml-network -lsfml-window -lsfml-graphics -lsfml-system

# Compile object file from main.cpp to main.o
main.o: main.cpp
	g++ -c -Werror -g main.cpp -o main.o -lm

# Remove all ~ and .o files
clean:
	rm -f main *~ *.o

# Make documentation files
docs:
	doxygen Doxyfile
