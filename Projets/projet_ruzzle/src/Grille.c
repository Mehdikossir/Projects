#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Grille.h"
#include "Booleen.h"

Grille G_grille (){
unsigned int i,j;
 Case** grille = (Case**) malloc (4*sizeof(Case*));
 for(i=0;i<4;i++)
       grille[i] = (Case*) malloc (4*sizeof(Case));
  for(i=0;i<4;i++)
   for(j=0;j<4;j++)
     grille[i][j]=C_initialisationCase('a',1,' ',FALSE);

return grille;
free (grille);
}

Case G_obtenirCase (Grille grille, Coordonnee coordonne ){
  return grille[coordonne.x][coordonne.y];
}

void G_modifierCase (Grille grille, Case uneCase, Coordonnee coordonnee){
    grille[coordonnee.x][coordonnee.y] = uneCase;
}

void G_changementDEtat (Grille grille, Coordonnee coordonne){
  grille[coordonne.x][coordonne.y].dejaUtilisee= !(grille[coordonne.x][coordonne.y].dejaUtilisee);
}
