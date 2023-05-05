prog:fonctions.o main.o
	gcc fonctions.o main.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c
fonctions.o:fonctions.c
	gcc -c fonctions.c
