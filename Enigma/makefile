prog: main.o enigma.o
	gcc main.o enigma.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
enigmas.o:enigma.c
	gcc -c enigma.c -g

