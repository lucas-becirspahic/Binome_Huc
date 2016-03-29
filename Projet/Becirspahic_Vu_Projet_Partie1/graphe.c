#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

void ajoute_liste_sommet(Cellule_som *liste,Sommet *s)
{
  Cellule_som *actu;
  if (liste == NULL) 
    actu->suiv = NULL;
  else 
    actu->suiv = liste->suiv;
  actu->sommet = s;
  liste = actu;
}

void detruire_liste_sommet(Cellule_som *liste, Sommet s)
{
  Cellule_som *actu;
  Cellule_som *temp;
  actu = liste;
  while(actu != NULL){
    temp = actu;
    actu = actu->suiv;
    free(temp);
  }
  liste = NULL;
}

int recherche_sommet(Cellule_som *liste, Sommet s)
{
  Cellule_som *actu;
  actu = liste;
  while(actu != NULL){
    if (actu->sommet == &s)
      return 1;
    actu = actu->suiv;
  }
  return 0;
}

int adjacent(Sommet *s1, Sommet *s2)
{
  int i;
  for(i = 0; i < s1->nbcase_som;i++){
    if(recherche_sommet(s1->sommet_adj,*s2))
      return 1;
  }
  return 0;
}

void ajoute_voisin(Sommet *s1, Sommet *s2)
{
  // on verifie qu il n y a pas de doublon dans la liste
  if (!(adjacent(s1,s2)))
    ajoute_liste_sommet(s1->sommet_adj, s2);
  // on verifie qu il n y a pas de doublon dans la liste
  if (!(adjacent(s2,s1)))
    ajoute_liste_sommet(s2->sommet_adj, s1);
}


void creer_sommet(Sommet *s, int num, int cl,Liste cases, int nbcase_som, Cellule_som *sommet_adj)
{
  s = (Sommet *)malloc(sizeof(Sommet *));
  s->num = num;
  s->cl = cl;
  s->cases = cases;
  s->nbcase_som = nbcase_som;
  s->sommet_adj = sommet_adj;
}

void actualise_mat(Graphe_zone *Graphe, Sommet s){
  Elnt_liste *actu = s.cases;
  while (actu != NULL){
    (Graphe->mat)[actu->i][actu->j] = &s;
    actu = actu->suiv;
  }
}

void creer_arete(Graphe_zone *Graphe, Grille *G)
{
  int i,j;
  for(i = 0; i < G->dim;i++){
    for(j = 0; j < G->dim;j++){
      if(i != (G->dim) -1 && ((Graphe->mat)[i][j]) != ((Graphe->mat)[i+1][j]))
	ajoute_voisin((Graphe->mat)[i][j],(Graphe->mat)[i+1][j]);
      
      if(i != 0 && ((Graphe->mat)[i][j]) != ((Graphe->mat)[i-1][j]))
	ajoute_voisin((Graphe->mat)[i][j],(Graphe->mat)[i-1][j]);
      
      if(j != (G->dim) -1 && ((Graphe->mat)[i][j]) != ((Graphe->mat)[i][j+1]))
	ajoute_voisin((Graphe->mat)[i][j],(Graphe->mat)[i][j+1]);
      
      if(j != 0 && ((Graphe->mat)[i][j]) != ((Graphe->mat)[i][j-1]))
	ajoute_voisin((Graphe->mat)[i][j],(Graphe->mat)[i][j-1]);
    }
  }
}

Graphe_zone* creer_graphe_zone(Grille *G, int **M)
{
  int i,j;
  int num = 0;
  Sommet s;
  Liste L;
  init_liste(&L);
  Graphe_zone *Graphe;
  Graphe = (Graphe_zone*)malloc(sizeof(Graphe_zone*));
  Graphe->nbsom = 0;
  Graphe->som = NULL;
  Graphe->mat = (Sommet ***)malloc(G->dim*sizeof(Sommet **));
  for(i = 0; i < G->dim; i++){
    (Graphe->mat)[i] = (Sommet**)malloc(G->dim*sizeof(Sommet**));
    for(j = 0; j < G->dim; j++){
      (Graphe->mat)[i][j] = (Sommet*)malloc(G->dim*sizeof(Sommet*));
      (Graphe->mat)[i][j] = NULL;
    }
  }
  for(i = 0; i < G->dim; i++){
    for(j = 0; j < G->dim; j++){
      if ((Graphe->mat)[i][j] == NULL){
	printf("toto\n");
	trouve_zone_rec(M,G,i,j,NULL,&L);
	printf("toto2\n");
	creer_sommet(&s, num, M[i][j], L,0,NULL);
	actualise_mat(Graphe,s);
      }
    }
  }

  //Elnt_liste *actu = (Graphe->mat)[0][0];
  for(i = 0; i < G->dim; i++){
    for(j = 0; j < G->dim; j++){
      printf("Case (%d,%d) dans sommet num %d  de couleur %d\n",i,j,(Graphe->mat)[i][j]->num, (Graphe->mat)[i][j]->cl);
    }
  }
  return Graphe;
}
