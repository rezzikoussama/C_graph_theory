#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include"graphs.h"

int main(){
system("COLOR 0B");
graph *G;
creatG(&G);
int d=0,*Matrice=NULL,dist,ordre,i,*eulerpath=NULL;
char *sommet,*voisins;
X *tmpX;
char c,u,v;
FILE *file;
menu:
	system("cls");
	printf("\tMENU:\n\n");
printf("   choisser la fonction que vous voulez applique:\n");
printf("\t1- ajoute un sommet \n");
printf("\t2- ajoute une arete \n");
printf("\t3- supprimer un sommet \n");
printf("\t4- supprimer une arete \n");
printf("\t5- afficher la matrice d'adjacence \n");
printf("\t6- calculer l'ordre de graph \n");
printf("\t7- calculer les degres des sommet de graph \n");
printf("\t8- afficher le voisingae d'un sommet \n");
printf("\t9- verifier l'existance d'un chemin de longeur L \n");
printf("\t10- afficher un chemin ou un cycle eulerien \n");
printf("\t11- afficher le graph \n");
printf("\t0- fermer \n");


printf("\n\n\t");
scanf("%d",&d);
switch (d){
case 1:
	system("cls");
	printf("\tentrez un lettre qui represent le sommet que vous voulez ajoute\n\t");
	printf("\n\n\t");
	getchar();
	scanf("%c",&c);
	printf("\n\n\t");
	addsommet(&G,c);
	system("pause");
	goto menu;
break;

case 2:	
	system("cls");
	printf("\entrez les lettre representant les deux extrimite de l'arete que vous voulez ajoute' 'u' et 'v'\n\tu:\t");
	getchar();
	scanf("%c",&u);
	printf("\n\n\tv:\t");
	getchar();
	scanf("%c",&v);
	getchar();
	printf("\tentrez le poid de l'arete\n\n\tdist:\t");
	scanf("%d",&dist);
	printf("\n\n\t");
	addarete(&G,u,v,dist);
	system("pause");
	goto menu;
	
break;

case 3:
	system("cls");
	printf("\tentrez un lettre qui represent le sommet que vous voulez supprime\n\t");
	getchar();
	scanf("%c",&c);
	printf("\n\n\t");
	deletesommet(&G,c);
	system("pause");
	goto menu;
	
break;

case 4:
	system("cls");
	printf("\entrez les lettre representant les deux extrimite de l'arete que vous voulez supprime 'u' et 'v'\n\tu:\t");
	getchar();
	scanf("%c",&u);
	printf("\n\n\tv:\t");
	getchar();
	scanf("%c",&v);
	getchar();
	printf("\n\n\t");
	deletearete(&G,u,v);
	system("pause");
	goto menu;
break;

case 5:
	system("cls");
	printf("\tla matrice d'ajacence est:\n\n");
	Matrice=matriceadjacence(G);
	if(Matrice!=NULL)
	afficherM(Matrice,G);
	free(Matrice);
	Matrice=NULL;
	printf("\n\n\t");
	system("pause");
	goto menu;
break;

case 6:
	system("cls");
	ordre=graphordre(G);
	printf("\n\tl'ordre de graph est :\t%d",ordre);
	printf("\n\n\t");
	system("pause");
	goto menu;
break;

case 7:
	system("cls");
	tmpX=G->X;
	sommet=(char*)malloc(G->n*sizeof(char));
    for(i=0;i<G->n;i++){
        sommet[G->n-1-i]=tmpX->sommet;
        tmpX=tmpX->next;
                    }
                    	printf("\n\n");
    for(i=0;i<G->n;i++){
       	printf("\td(%c)=\t%d\n",sommet[i],sommetdegre(G,sommet[i]));
		}
		free(sommet);
	printf("\n\n\t");
	system("pause");
	goto menu;
break;



case 8:
	system("cls");
	printf("\n\tentrez le sommet :\t");
	getchar();
	scanf("%c",&c);
	printf("\n\t");
	voisins=voisinage(G,c);
	printf("\n\n\t");
	system("pause");
	goto menu;
break;

case 9:
	system("cls");
	printf("\n\n\t");
	printf("\n\tentrez le sommet de depart :\t");
	getchar();
	scanf("%c",&u);
	printf("\n\tentrez le sommet de l'arrivée' :\t");
	getchar();
	scanf("%c",&v);
	existilunchemin(G,indice(G,u),indice(G,v));
	system("pause");
	goto menu;
break;

case 10:
	system("cls");
	eulerpath=eulerien(G);
	printf("\n\n\t");
	system("pause");
	goto menu;

break;

case 11:
	file=fopen("tmp/graph.fichier","w+");
	fprintf(file,"%d",G->n);
	Matrice=Madjacence(G);
	for(i=0;i<G->n*G->n;i++){
	fprintf(file,"%d",Matrice[i]);}
	for(i=0;i<G->n;i++){
	fprintf(file,"%c",charindice(G,G->n-i-1));
	}
	fclose(file);
	free(Matrice);
	Matrice=NULL;
	system("graphdrawing.exe");

	goto menu;
break;

case 0:
	system("cls");
	goto end;
break;
}
end:
	printf("\n\tmerci d'utilise notre programme\n\n\t");
	printf("\n\n\t");

system("pause");
return 1;}
