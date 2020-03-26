#ifndef __FONCTIONS_PRINCIPALES__
#define __FONCTIONS_PRINCIPALES__

#include <stdio.h>
#include "Case.h"
#include "Dictionnaire.h"
#include "CasesContigues.h"
#include "Grille.h"
#include "Booleen.h"
#include "ArbreBinaireDeLettres.h"
#include "ListeOrdonnee.h"

/** chargerLeDictionnaire permet de charger en mémoire un dictionnaire à partir d'un fichier sérialisé et d'un dico vide*/
void chargerLeDictionnaire (Dictionnaire* pdico, FILE* fic);
/** initialiserGrille permet de creer une grille à partir d'une chaine de
*   caractères qui serra demandé à l'aide d'un scanf.*/
Grille initialiserGrille (char* chaineDeCaractereDecrivantLaGrille);
/** ruzzleSolveur est une fonction permettant de parcourir les 16 cases de notre
*   grille et de trouver les mots dont la lettre commence par lettre de la case
*   selectionné. Elle fait appel à la fonction récursive rechercheDeMot*/
ListeChainee ruzzleSolveur (Grille grille, Dictionnaire dico);
/** rechercheDeMot est une procédure récursive permettant de rechercher les mots
*   dans la grille*/
void rechercheDeMot (Grille grille, Coordonnee coordonnee, CasesContigues casesContigues, ListeChainee* resultat, Dictionnaire dico);

#endif
