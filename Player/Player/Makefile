prog:player.o main.o background.o image.o
	gcc background.o main.o player.o image.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
player.o:player.c
	gcc -c player.c -g
background.o:background.c
	gcc -c background.c -g
image.o:image.c
	gcc -c image.c -g
