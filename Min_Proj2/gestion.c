#include <stdio.h>
#include <stdlib.h>
//#include
//#include


int main(){

  boolean fin = false;
  char choix;

  do{
     printf("Menu : choisissez une fonction\n");
     printf("1 - Recherche d'un ouvrage par son numero\n");
     printf("2 - Recherche d'un ouvrage par son titre\n");
     printf("3 - Recherche de tous les livres d'un meme auteur\n");
     printf("4 - Insertion d'un nouvel ouvrage\n");
     printf("5 - Suppression d'un ouvrage\n");
     printf("6 - Recherche des ouvrages au moins en double\n");
     printf("7 - Quitter\n")

       choix = getchar();

     switch(choix){

     case '1' :
       printf("1 - Recherche d'un ouvrage par son numero\n");
    
       /* code */
    
       break;

     case '2' :
       printf("2 - Recherche d'un ouvrage par son titre\n");

       /* code */

       break;

     case '3' :
       printf("3 - Recherche de tous les livres d'un meme auteur\n");

       /* code */

       break;

     case '4' :
       printf("4 - Insertion d'un nouvel ouvrage\n");

       /* code */

       break;

     case '5' :
       printf("5 - Suppression d'un ouvrage\n");

       /* code */

       break;

     case '6' :
       printf("6 - Recherche des ouvrages au moins en double\n");

       /* code */

       break;

     case '7' :
       printf("7 - Quitter\n");

       fin = true;

       break;

     default :
       printf("Erreur de saisie\n");
  }
  while{fin == false;}
 
    
  }
  
}
