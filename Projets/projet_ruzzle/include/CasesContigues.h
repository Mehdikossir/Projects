#ifndef __CASESCONTIGUES__
#define __CASESCONTIGUES__

#include <string.h>
#include "Booleen.h"
#include "Case.h"
#include "Mot.h"

 /** CasesContigues est un pointeur sur un Noeud, le Noeud étant une structure
 * constitué d'une case et d'une casesContigues (suivante) ce nouveau type
 * servira à stocker un chemin de cases parcouru dans la grille ( c'est une
 * liste chainée) */
typedef struct Noeud* CasesContigues;
typedef struct Noeud {
                Case uneCase ;
      CasesContigues casesSuivantes;
} Noeud;

/** CC_casesContigues crée une casesContigues vide  */
CasesContigues CC_casesContigues ();
/** CC_estVide permet de vérifier si desCasesContigues est vide */
Booleen CC_estVide (CasesContigues desCasesContigues);
/** CC_estPresent permet de savoir si uneCase est présente dans desCasesContigues*/
Booleen CC_estPresent (CasesContigues desCasesContigues, Case uneCase);
/** CC_ajouterCase permet d'ajouter uneCase à desCasesContigues*/
void CC_ajouterCase (CasesContigues* desCasesContigues, Case uneCase);
/** CC_obtenirCase permet d'obtenir la Case de desCasesContigues*/
Case CC_obtenirCase (CasesContigues desCasesContigues);
/** CC_fixerCasesContiguesSuivante permet d'ajouter casesContiguesAFixer à desCasesContigues */
void CC_fixerCasesContiguesSuivante (CasesContigues* desCasesContigues, CasesContigues casesContiguesAFixer);
/** CC_longueur permet d'obtenir la longueur de desCasesContigues */
unsigned int CC_longueur (CasesContigues desCasesContigues);
/** CC_obtenirCasesSuivantes permet d'obtenir la CasesContigues suivante   */
CasesContigues CC_obtenirCasesSuivantes (CasesContigues desCasesContigues);
/** CC_scoreCasesContiguesSansBonusMot donne le score obtnue pas desCasesContigues
* sans prendre en compte les bonnus de mot */
unsigned int CC_scoreCasesContiguesSansBonusMot (CasesContigues desCasesContigues);
/** CC_scoreCasesContigues donne le score obtnue pas desCasesContigues */
unsigned int CC_scoreCasesContigues(CasesContigues desCasesContigues);
/** CC_casesContiguesEnMot transforme desCasesContigues en un mot */
Mot CC_casesContiguesEnMot (CasesContigues desCasesContigues);
/** CC_supprimerTeteCase surpprime la premiére CasesContigues de desCasesContigues */
void CC_supprimerTeteCase (CasesContigues* desCasesContigues);
/** CC_supprimer supprime desCasesContigues*/
void CC_supprimer (CasesContigues* desCasesContigues);

#endif
