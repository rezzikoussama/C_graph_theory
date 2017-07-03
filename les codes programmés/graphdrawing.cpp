#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL_image.h>
#include<math.h>
#define PI 3.14159265

void pause();
int main (int argc, char *argv[]){
SDL_Surface *ecran = NULL, *imageDeFond = NULL,*point=NULL;
SDL_Rect positionFond,pointxy;

SDL_Init(SDL_INIT_VIDEO);
SDL_WM_SetIcon(IMG_Load ("tmp/png/ICONE.png"), NULL);
ecran = SDL_SetVideoMode(1000,700, 32, SDL_HWSURFACE);
SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,250,250,250));
SDL_WM_SetCaption("graph", NULL);
point = IMG_Load ("tmp/png/point.png");

FILE *file;
float o;

file = fopen("tmp/graph.fichier", "r");
int k = 0,j,i,Lx,Ly,m;
fscanf(file, "%1d", &k);
char *sommet,s;
int *matrice;

sommet=(char*)malloc(k*sizeof(char));
matrice=(int*)malloc(k*k*sizeof(int));


    for (j=0;j<k*k;j++)
    {
      fscanf(file, "%1d", &matrice[j]);
    }
    for (j=0;j<k+1;j++)
    {
      fscanf(file, "%c", &sommet[j]);
    }


  fclose (file);
    int Px[k],Py[k];
    for(j=0;j<k;j++){
    	o=(float)((float)j/(float)k)*PI*2;
        Px[j]=(int)(500+300*cos(o));
        Py[j]=(int)(350+300*sin(o));}
    for(i=0;i<k;i++)for(j=0;j<k;j++){
        if(matrice[i*k+j]==1){
                Lx=Px[i]-Px[j];
                Ly=Py[i]-Py[j];

                for(m=0;m<5000;m++){
                    pointxy.x=Px[j]+((m*Lx)/5000);
                    pointxy.y=Py[j]+((m*Ly)/5000);
                    SDL_BlitSurface(point , NULL, ecran, &pointxy );

                }
        }

    }




char pnglink[]="tmp/png/A.png";
for (j=0;j<k+1 ;j++){
pnglink[8]=sommet[k-j-1];
imageDeFond = IMG_Load (pnglink);
positionFond.x=Px[j]-25;
positionFond.y=Py[j]-25;
SDL_BlitSurface(imageDeFond , NULL, ecran, &positionFond );
}
SDL_Flip(ecran);
pause();
SDL_FreeSurface(imageDeFond );
SDL_Quit();
return EXIT_SUCCESS;
}
void pause()
{
int continuer = 1;
SDL_Event event;
while (continuer)
{
SDL_WaitEvent(&event);
switch(event.type)
{
case SDL_QUIT:
continuer = 0;
}}}

