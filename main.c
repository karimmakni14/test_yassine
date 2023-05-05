
#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include"fonctions.h"
int main()
{
	int boocle=1;
	SDL_Event event;
	SDL_Surface *screen;
	perso p;
	image back;
	vie_player v;
	score_info s;
	screen=SDL_SetVideoMode(596,487,32,SDL_HWSURFACE|SDL_SRCALPHA);
	TTF_Init();
	initPerso(&p);
	initialiser_back(&back);
	init_scoreTexte(&s);
	init_imageVies(&v);
	s.score=100;
	while (boocle==1)
	{
		afficher_imge(screen,back);
		afficherPerso(p,screen);
		afficher_imageVies(screen,v);
		afficher_scoreTexte(screen,s);
		animerPerso (&p);
		
		if(p.saut==1) saut(&p);
		else if(p.etat==0) movePerso (&p);
		
		while(SDL_PollEvent(&event))
		{
		switch(event.type)
		{
			case SDL_QUIT:
				boocle=0;
				break;
			case SDL_KEYDOWN:
	
				if(event.key.keysym.sym==SDLK_RIGHT)
				{
					p.etat=0;
					p.dirrections=0;
					p.pos.w=85;
					p.pos.h=120;
					p.v=20;
				}
				else if(event.key.keysym.sym==SDLK_DOWN)
				{
					if(p.saut!=1)
					{
						p.etat=4;
						p.mouvment=1;
						p.pos.w=68;
						p.pos.h=117;
					}
				}
				else if(event.key.keysym.sym==SDLK_UP)
				{
					if(p.saut!=1)
					{
						p.saut=1;
						p.mouvment=-1;
						p.pos.w=78;
						p.pos.h=123;
					}
				}
				if(event.key.keysym.sym==SDLK_LEFT)
				{
					p.etat=0;
					p.dirrections=1;
					p.pos.w=85;
					p.pos.h=120;
					p.v=20;
				}
				if(event.key.keysym.sym==SDLK_r)
				{
					p.etat=0;
					p.pos.w=85;
					p.pos.h=120;
					p.v=10;
				}
				break;
			case SDL_KEYUP:
				if(event.key.keysym.sym==SDLK_RIGHT 
				&& p.dirrections==0)
				{
					p.etat=1;
					p.pos.w=67;
					p.pos.h=119;
				}
				else if(event.key.keysym.sym==SDLK_DOWN
				&& p.etat==4)
				{
					p.etat=1;
					p.pos.w=67;
					p.pos.h=119;
				}
				else if(event.key.keysym.sym==SDLK_LEFT 
				&& p.dirrections==1)
				{
					p.etat=1;
					p.pos.w=67;
					p.pos.h=119;
				}
		
				break;
			
		}
		}
	SDL_Flip(screen);
	SDL_Delay(75);
	}
	SDL_FreeSurface(screen);
	SDL_FreeSurface(p.etat_droite.img);
	SDL_FreeSurface(p.etat_gauche.img);
}
//initialisations du song continue musique=Mix_LoadMUS("musique.mp3");
//initialisations du song bref son_bref=Mix_LoadWAV( "effet.wav" );
//affichage du song continue Mix_PlayMusic(musique,-1);
//affichage du song bref Mix_PlayChannel( -1,song_bref,0);
//liberation du song continue Mix_FreeMusic(musique);
//liberation du song bref Mix_FreeChunk(song_bref);
//liberation des image SDL_FreeSurface(nom_image.img);
/*liberations du text TTF_CloseFont (nom_text.police); 
  SDL_FreeSurface(nom_text.txt);
  TTF_Quit();*/
