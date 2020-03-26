#ifndef _CASE_H_
#define _CASE_H_

#include <string.h>
#include "Booleen.h"


/** Le type bonus peu prendre 5 valeurs, soit rien (VD),soit lettre compte double
* (LD), soit lettre compte triple (LT),soit mot compte double(MD),soit mot compte
* triple (MT). La valeur asssociée est la somme des caractères ascii correspondant*/

typedef enum {VD=154,LD=144,LT=160,MD=145,MT=161} Bonus;

/** Une Case  est defini par le caractère qu'elle comptient, le nombre de points associé
* à cette lettre, le bonus aussi associé et un booleen qui permet de savoir si la
* case a deja été selectionné dans le processus de cases Contigues.*/

typedef struct Case {
	             char lettre;
       unsigned int nbPoints;
              Bonus bonus;
            Booleen dejaUtilisee;
} Case;

/** C_initialisationCase initialise une case à partir de 4 parametres données.*/
Case C_initialisationCase(char lettre, unsigned int nbPoints, Bonus bonus,Booleen dejaUtilisee);
/** C_obtenirNbPoints obtient le nombre point associé à la case.*/
unsigned int C_obtenirNbPoints (Case uneCase);
/** C_obtenirLettre obtient la lettre associée à la case.*/
char C_obtenirLettre (Case uneCase);
/** C_obtenirBonus obtient le bonus associé à la case.*/
Bonus C_obtenirBonus (Case uneCase);
/** C_estDejaUtilisee obtient le booleen associé à la case.*/
Booleen C_estDejaUtilisee (Case uneCase);
/** C_sontEgales permet de savoir si deux cases sont égales.*/
Booleen C_sontEgales(Case uneCase1,Case uneCase2);
/** C_bonusLettreEnNaturel transforme le bonus de la lettre en nombre (ex : LD -> 2).*/
unsigned int C_bonusLettreEnNaturel (Case uneCase);
/** C_bonusMotEnNaturel transforme le bonus du mot en nombre (ex : MD -> 2).*/
unsigned int C_bonusMotEnNaturel (Case uneCase);

#endif
