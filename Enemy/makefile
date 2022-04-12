prog: enemy.o main.o
	gcc main.o enemy.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o: main.c
	gcc -c main.c -g
enemy.o: enemy.c
	gcc -c enemy.c -g
