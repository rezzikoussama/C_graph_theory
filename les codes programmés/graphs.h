#include<stdio.h>
#include<stdlib.h>
/**STRUCTRE(sommet)*/
typedef struct X{
                 char sommet;
                 struct X *next; }X;
/**STRUCTRE(arete)*/

typedef struct U{int distance;
                 char a1;
                 char a2;
                 struct U *next; }U;
/**STRUCTRE(graph)*/
typedef struct graph{
                 struct X *X;
                 struct U *U;
                 int m,n;}graph;
/**creer un graphe*/

void creatG(graph **G){
    *G=(graph*)malloc(sizeof(graph)+sizeof(int)*2+sizeof(struct X)+sizeof(struct U));
                (*G)->X=NULL;
                (*G)->U=NULL;
                (*G)->n=0;
                (*G)->m=0;
};
/**ajouter une sommet*/
void addsommet(graph **G,char c){
        X *X;
        X=(struct X*)malloc(sizeof(X)+sizeof(char));
        X->sommet=c;
        X->next=(*G)->X;
        (*G)->X=X;
        (*G)->n+=1;}
/**ajouter une arete*/
void addarete(graph **G,char a1,char a2,int d){
        U *U;
        U=(struct U*)malloc(sizeof(U)+sizeof(char)*2+sizeof(int));
        U->a1=a1;
        U->a2=a2;
        U->distance=d;
        U->next=(*G)->U;
        (*G)->U=U;
        (*G)->m+=1;}
/**suprimer un sommet*/
 void deletesommet(graph **G,char c){

    if((*G)->X!=NULL){
    int n=0;
    X *precedent=(*G)->X;
    X *tmp=precedent->next;
    if(precedent->sommet==c){
        (*G)->X=tmp;
        free(precedent);
        (*G)->n=(*G)->n-1;
    }
    else{
    while(precedent!=NULL&&n!=1){
            if(tmp->sommet==c){ n=1;
                                precedent->next=tmp->next;
                                (*G)->n=(*G)->n-1;
                                free(tmp);
                              }

            precedent=tmp;
            if(tmp!=NULL){
                         tmp=tmp->next;
                         }
                        }}}

    if((*G)->U!=NULL){
    int m=0;

    U *tmpU=(*G)->U;
    U *precedentU=(*G)->U;

    while(tmpU!=NULL){

        if(tmpU->a1==c||tmpU->a2==c){
        if(tmpU==precedentU){
        (*G)->U=tmpU->next;
        free(tmpU);
        (*G)->m-=1;
        tmpU=(*G)->U;
        precedentU=tmpU;
        m=1;                                      }

        if(tmpU!=precedentU){
        (*G)->m-=1;
        precedentU->next=tmpU->next;
        free(tmpU);
        tmpU=precedentU->next;
        m=1;                            }}
            if(m==0&&tmpU!=NULL){ precedentU=tmpU;
                    tmpU=tmpU->next;
                    }
m=0;
}

    }}
 /**supprimer une arete*/
void deletearete(graph **G,char a1,char a2){
    if((*G)->U!=NULL){
    int m=0;

    U *tmpU=(*G)->U;
    U *precedentU=(*G)->U;
    while(tmpU!=NULL){

        if((tmpU->a1==a1&&tmpU->a2==a2)||(tmpU->a1==a2&&tmpU->a2==a1)){
        if(tmpU==precedentU){
        (*G)->U=tmpU->next;
        free(tmpU);
        (*G)->m-=1;
        tmpU=(*G)->U;
        precedentU=tmpU;
        m=1;                                      }

        if(tmpU!=precedentU){
        (*G)->m-=1;
        precedentU->next=tmpU->next;
        free(tmpU);
        tmpU=precedentU->next;
        m=1;                            }}
            if(m==0&&tmpU!=NULL){ precedentU=tmpU;
                    tmpU=tmpU->next;
                    }
m=0;
}

    }}
/**degre d'un sommet apartir d'un graph*/
int sommetdegre(graph *G,char c){
	U *tmpU=G->U;
	int d=0;
	while(tmpU!=NULL){
		if (tmpU->a1==c||tmpU->a2==c)d++;
		tmpU=tmpU->next;}
	return d;
}
/**matrice d'adjacence avec les poid*/
int *matriceadjacence(graph *G){
	if(G->U!=NULL){
    int n=G->n,i,j,d=0;
    char sommet[n],a1,a2;
    int *T=(int*)calloc(n*n,sizeof(int));

    X *tmpX=G->X;
        for(i=0;i<n;i++){
            sommet[n-1-i]=tmpX->sommet;
            tmpX=tmpX->next;
                        }
    U *tmpU=G->U;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a1=sommet[i];
            a2=sommet[j];
            while(tmpU!=NULL){
            if((tmpU->a1==a2&&tmpU->a2==a1)){d=tmpU->distance;}
            if((tmpU->a1==a1&&tmpU->a2==a2)){d=tmpU->distance;}
            tmpU=tmpU->next;
            }
            T[i*n+j]=d;
            d=0;
            tmpU=G->U; }}
return T;}
else{return NULL;}
}
/**l'ordre de graph*/
int graphordre(graph *G){
	return G->n;
}
 /**matrice d'adjacence sans les poid (pour l'utiliser dans les autres fonction)*/
int *Madjacence(graph *G){
if(G->U!=NULL){
    int n=G->n,i,j,d=0;
    char sommet[n],a1,a2;
    int *T=(int*)calloc(n*n,sizeof(int));

    X *tmpX=G->X;
        for(i=0;i<n;i++){
            sommet[n-1-i]=tmpX->sommet;
            tmpX=tmpX->next;
                        }
    U *tmpU=G->U;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a1=sommet[i];
            a2=sommet[j];
            while(tmpU!=NULL){
            if((tmpU->a1==a2&&tmpU->a2==a1)){d++;}
            if((tmpU->a1==a1&&tmpU->a2==a2)){d++;}
            tmpU=tmpU->next;
            }
            T[i*n+j]=d;
            d=0;
            tmpU=G->U; }}
return T;}
else{return NULL;}
}
/**afficher une matrice*/
void afficherM(int *p,graph *G){
int i,j,n=G->n;
char sommet[n];
X *tmpX=G->X;
        for(i=0;i<n;i++){
            sommet[n-1-i]=tmpX->sommet;
            tmpX=tmpX->next;
                        }
                        printf("\n\t");
                        for(i=0;i<n;i++)printf("%c\t",sommet[i]);
for(i=0;i<n;i++){printf("\n%c\t",sommet[i]);
for(j=0;j<n;j++){
printf("%d\t",*(p+i*n+j));}
}}
/**voisinage d'un sommet*/
char *voisinage(graph *G,char c){
	int i=0,n=sommetdegre(G,c);
	char *T=(char*)malloc(sizeof(char));
	U *tmpU=G->U;
	while(tmpU!=NULL){
		if(tmpU->a1==c){
			T[i]=tmpU->a2;
			i++;
		}
		else{
		 if(tmpU->a2==c){
			T[i]=tmpU->a1;
			i++;
		}}
		tmpU=tmpU->next;
	}printf("%c[]",c);
	for(i=0;i<sommetdegre(G,c);i++)printf("->[%c]",*(T+i));
	return T;
}
/**indice d'un sommet*/
int indice(graph *G,char c){
	int i=G->n-1,n;
	X *tmpX=G->X;
	while(tmpX->sommet!=c){i--;
	tmpX=tmpX->next;
	}
	return i;
}
/**sommet d'un indice*/
char charindice(graph *G,int c){
	char a;
	int j=G->n,i;
	X *tmpX=G->X;
	for(i=0;i<j-c-1;i++){
	tmpX=tmpX->next;
	}
	a=tmpX->sommet;
	return a;
}
/**degre d'un sommet apartir d'un matrice d'adjacence*/
int sommetdegreMa(graph *G,int *T,char c){
	int d=0,i,k=indice(G,c);
	for(i=0;i<G->n;i++){
		d+=*(T+k+i*G->n);
	}
	
	return d;
}
/**vérifier si la matrice est vide*/
int checkM(int*T,int n){
	int i,d=0;
	for(i=0;i<n*n;i++){
		d+=*(T+i);
	}
	return d;
} 
/**retourner une tableau des indice des sommet*/
int *indicesommets(graph *G){
	int *sommet=(int*)malloc(G->n*sizeof(int)),i;
	for(i=0;i<G->n;i++){
            sommet[i]=0;
                        }
                        return sommet;
}
/**nombre de sommets lieé a un sommet*/
int sommetconnex(graph *G,int *M,int c,int *sommet){
int j,n=G->n,i,k=0;
sommet[c]=1;
for(j=0;j<n;j++){
if(M[c*n+j]==1){
M[c*n+j]=0;
M[c+n*j]=0;
sommet[j]=1;/**pour quelle ne se compte plus*/ 
sommetconnex(G,M,j,sommet);
}}
for(j=0;j<n;j++)k+=sommet[j];
return k;}
/**______________________________________________________*/
/**-si on peut cosidirer l'arc suivant comme arete suivant-*/
int checkbridge(graph *G,int *M,int u,int v){
	int count1,count2,*sommet,i,*M2=(int*)malloc(G->n*G->n*sizeof(int)),*M1=(int*)malloc(G->n*G->n*sizeof(int));
	if(sommetdegreMa(G,M,charindice(G,u))==1){
		return 1;
	}
	else{
			for(i=0;i<G->n*G->n;i++){
			M1[i]=M[i];
			M2[i]=M[i];
			}
		sommet=indicesommets(G);
		count1=sommetconnex(G,M1,u,sommet);
		M2[u*G->n+v]=0;
		M2[u+v*G->n]=0;
		sommet=indicesommets(G);
		count2=sommetconnex(G,M2,u,sommet);
	free(sommet);
	free(M2);
	free(M1);

	}
	if(count1>count2){
	return 0;}
	else{
	return 1;
	}
}

/**imprimer un ou un cycle chemin eulerien*/
void printeulerien(graph *G,int *T){
	int i;	
	printf("\n\n\t");
	for(i=0;i<G->m;i++)
	printf("%c-%c\t",charindice(G,*(T+i*2)),charindice(G,*(T+i*2+1)));
}
/**cylcle ou chemin eulerien*/
int *eulerien(graph *G){
	int i,tmp=0,u=0,d=0,k=0;
	for(i=0;i<G->n;i++){
		if(sommetdegre(G,charindice(G,i))%2==1)
		tmp++;
	}
	i=0;
	if(tmp==0){
	printf("\n\n\til existe une cycle eulerien\n");
	}else{
	if(tmp==2){
	printf("\n\n\til existe un chemin eulerien\n");
	if(tmp==2){while(sommetdegre(G,charindice(G,i))%2==0){
	/**avoir l'indice d'un sommet du degre impaire*/
	i++;	}
	u=i;
	}
	}
	else {printf("\n\n\til n'existe pas un chemin ou une cycle eulerien dans ce graph\n");
	return NULL;}}
/**application d'algorithme du Fleury pour avoir un chemin*/
i=0;
	int	*T=(int*)calloc(2*G->m,sizeof(int));
		int *M;
		M=Madjacence(G);
		while(checkM(M,G->n)!=0){
		for(i=0;i<G->n;i++){
		if(M[u*G->n+i]==1 && checkbridge(G,M,u,i)==1){
			T[k*2]=u;
			T[k*2+1]=i;
			k++;
			M[i*G->n+u]=0;
			M[i+u*G->n]=0;
			u=i;
			i=0;
		}}
		
	}
	printeulerien(G,T);
	return T;}

/**une fonction qui retourne un tableau avec les plus court chemin apartir d'un sommet vers to les autres sommet*/
int *longeurdeschemins(graph *G,int *M /**matrice des longeurs*/,int u /**indice de sommet de depart*/){
	int i,j,*T=(int*)malloc(sizeof(int)),d,k,n=G->n;
for(k=0;k<n;k++)
	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        	if(M[i*n+j]!=0&&M[u*n+i]!=0){
        		
        	if(M[j+i*n]+M[i+u*n]<M[j+u*n]){
        
        	M[j+u*n]=M[j+i*n]+M[i+u*n];	
			M[u+j*n]=M[j+u*n];
			}
			
        	if(M[j+u*n]==0){
        		
				M[u+j*n]=M[j+i*n]+M[i+u*n];
				M[j+u*n]=M[u+j*n];
				}

		}}}
	
		for(i=0;i<n;i++)T[i]=M[i+u*n];
		free(M);

	return T;
}
/**une fonction qui retourne l'existance et la longeur de chemin entre 2 sommets*/
void existilunchemin(graph *G,int u /**indice de sommet de départ*/,int v /**indice de sommet d'arrivée*/){
int *i=longeurdeschemins(G,matriceadjacence(G),u);
if(i[v]==-1)printf("\n\til n'exist pas un chemin entre %c et %c",charindice(G,u),charindice(G,v));
else printf("\n\til existe un chemin entre %c et %c de longeur %d\n",charindice(G,u),charindice(G,v),i[v]);
}


