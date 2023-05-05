#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
	SDL_Rect pos1;
	SDL_Rect pos2;
	SDL_Surface *img;
}image;
typedef struct
{
	SDL_Surface *img;
	SDL_Rect pos[5][6];
	
}player;
typedef struct
{
	player etat_droite;
	player etat_gauche;
	SDL_Rect pos;
	int dirrections;
	int etat;
	int mouvment;
	int saut;
	int v;
}perso;
typedef struct
{
	SDL_Rect pos;
	TTF_Font *police;
	SDL_Surface *txt;
	SDL_Color color;
	int score;
	char ch[20];
}score_info;
typedef struct
{
	SDL_Rect pos;
	SDL_Surface *img;
}vie_player;
void initialiser_back(image *back);
void afficher_imge(SDL_Surface *screen,image imge);
void initPerso(perso *p);
void afficherPerso(perso p, SDL_Surface * screen);
void movePerso (perso *p);
void animerPerso (perso* p);
void saut (perso* p);
void initialiser_back(image *back);
void reanisyaliser(int *y,int *h,int *w,int i);
void afficher_imge(SDL_Surface *screen,image imge);
void init_imageVies(vie_player *v);
void afficher_imageVies(SDL_Surface *screen,vie_player v);
void afficher_scoreTexte(SDL_Surface *screen,score_info s);
void init_scoreTexte(score_info *s);
#endif
