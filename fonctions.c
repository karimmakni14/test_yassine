#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include"fonctions.h"
void initialiser_back(image *back)
{
	(*back).img=IMG_Load("image/unnamed.png");
	(*back).pos1.x=0;
	(*back).pos1.y=0;
	(*back).pos2.x=0;
	(*back).pos2.y=0;
	(*back).pos2.h=487;
	(*back).pos2.w=596;
}
void afficher_imge(SDL_Surface *screen,image imge)
{
	SDL_BlitSurface(imge.img,&imge.pos2,screen,&imge.pos1);
}
void initPerso(perso *p)
{
	int x,y,h,w;
	(*p).etat_droite.img=IMG_Load("image/speetshit_droite.png");
	(*p).etat=1;
	(*p).dirrections=0;
	(*p).mouvment=0;
	(*p).pos.w=67;
	(*p).pos.h=119;
	for(int i=0;i<5;i++)
	{
		x=0;
		reanisyaliser(&y,&h,&w,i);
		for(int j=0;j<6;j++)
		{
			(*p).etat_droite.pos[i][j].x=x;
			(*p).etat_droite.pos[i][j].y=y;
			(*p).etat_droite.pos[i][j].h=h;
			(*p).etat_droite.pos[i][j].w=w;
			x=x+w;
			if(i==4 && j==2) break; 
		}
	}
	(*p).etat_gauche.img=IMG_Load("image/speetshit_gauche.png");
	for(int i=0;i<5;i++)
	{
		x=504;
		reanisyaliser(&y,&h,&w,i);
		for(int j=0;j<6;j++)
		{
			x=x-w;
			(*p).etat_gauche.pos[i][j].x=x;
			(*p).etat_gauche.pos[i][j].y=y;
			(*p).etat_gauche.pos[i][j].h=h;
			(*p).etat_gauche.pos[i][j].w=w;
			
			if(i==4 && j==2) break; 
		}
	}
	(*p).pos.x=100;
	(*p).pos.y=350;
}
void reanisyaliser(int *y,int *h,int *w,int i)
{
	if(i==0) 
	{
		*y=0;
		*h=120;
		*w=85;
	}
	else if(i==1)
	{
		*y=120;
		*h=119;
		*w=67;
	}
	else if(i==2)
	{
		*y=239;
		*h=120;
		*w=72;
	}
	else if(i==3)
	{
		*y=359;
		*h=123;
		*w=78;
	}
	else if(i==4)
	{
		*y=482;
		*h=117;
		*w=68;
	}
}
void afficherPerso(perso p, SDL_Surface * screen)
{
	if(p.dirrections==0 && p.saut==1)
SDL_BlitSurface(p.etat_droite.img,&p.etat_droite.pos[3][p.mouvment],screen,&p.pos);
	else if (p.dirrections==1 && p.saut==1)
SDL_BlitSurface(p.etat_gauche.img,&p.etat_gauche.pos[3][p.mouvment],screen,&p.pos);
	else if(p.dirrections==0)
SDL_BlitSurface(p.etat_droite.img,&p.etat_droite.pos[p.etat][p.mouvment],screen,&p.pos);
	else
SDL_BlitSurface(p.etat_gauche.img,&p.etat_gauche.pos[p.etat][p.mouvment],screen,&p.pos);
}
void animerPerso (perso* p)
{
	(*p).mouvment++;
	if((*p).mouvment==6)
	(*p).mouvment=0;
	else if((*p).etat==4)(*p).mouvment=1;
}
void movePerso (perso *p)
{
	if((*p).dirrections==0 && (*p).pos.x<=400) 
		(*p).pos.x=(*p).pos.x+(*p).v;
	else if((*p).dirrections==1 && (*p).pos.x>=100)
		(*p).pos.x=(*p).pos.x-(*p).v;
}
void saut (perso* p)
{
	if((*p).etat==0)
	{
		if((*p).dirrections==0 && (*p).pos.x<=400) 
			(*p).pos.x=(*p).pos.x+(*p).v;
		else if ((*p).dirrections==1 && (*p).pos.x>=100)
			(*p).pos.x=(*p).pos.x-(*p).v;
	}
	if((*p).mouvment<3) (*p).pos.y=(*p).pos.y-50;
	else (*p).pos.y=(*p).pos.y+50;
	if ((*p).mouvment==5) (*p).saut=0;
}
void init_imageVies(vie_player *v)
{
	(*v).img=IMG_Load("image/vie.png");
	(*v).pos.x=0;
	(*v).pos.y=40;
}
void afficher_imageVies(SDL_Surface *screen,vie_player v)
{
	SDL_BlitSurface(v.img,NULL,screen,&v.pos);
}
void afficher_scoreTexte(SDL_Surface *screen,score_info s)
{
	char ch1[20];
	strcpy(ch1,"SCORE : ");
	sprintf(s.ch,"%d",s.score);
	strcat(ch1,s.ch);
	s.txt= TTF_RenderText_Blended(s.police,ch1, s.color);
        SDL_BlitSurface(s.txt, NULL, screen, &s.pos);
}
void init_scoreTexte(score_info *s)
{
	
	(*s).police=TTF_OpenFont("police/Ubuntu-Bold.ttf", 20);
	(*s).color.r = 0;
	(*s).color.g = 0;
	(*s).color.b = 0;
	(*s).pos.x=0;
	(*s).pos.y=0;
}

