all: main animal
main: main.cpp animal
	g++ -pedantic-errors -g main.cpp animal -o main
animal: animal.cpp animal.h
	g++ -pedantic-errors -g -c animal.cpp -o animal