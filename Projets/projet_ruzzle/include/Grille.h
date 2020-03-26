#ifndef _GRILLE_
#define _GRILLE_

#include "Case.h"
#include <stdio.h>

/** Le type Grille correspondant a un tableau de deux dimensions de cases*/
typedef Case** Grille;

/** Le type Coordonnee est définie par deux entires;l'abscisse et l'ordonnee*/
typedef struct Coordonnee {
                      int x;
                      int y;
} Coordonnee;

/** C_grille initialise une grille 4*4.*/
Grille G_grille ();
/** C_obtenirCase obtient la case d'une grille a une coordonne donnée.*/
Case G_obtenirCase (Grille grille,Coordonnee coordonne);
/** G_modifierCase modifie la case d'une grille a une coordonne donnée.*/
void G_modifierCase (Grille grille, Case uneCase, Coordonnee coordonnee);
/* G_changementDEtat modifie l'etat de la case d'une grille .*/
void G_changementDEtat (Grille grille,Coordonnee coordonnee);

#endif
