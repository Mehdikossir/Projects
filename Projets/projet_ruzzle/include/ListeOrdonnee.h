#ifndef _ListeOrdonnee_
#define _ListeOrdonnee_

#include <string.h>
#include "CasesContigues.h"
#include "Mot.h"
#include "Booleen.h"

/** La structure resultat est contitué d'un mot et d'un score.*/
typedef struct Resultat {
                    Mot mot;
           unsigned int score;
} Resultat;

/** La SDD ListeChainee permet de regrouper l'ensemble des scores dans l'ordre
*   croissant.*/
typedef struct L_Noeud* ListeChainee;
typedef struct L_Noeud {
              Resultat Resultat;
          ListeChainee listeSuivante;
} L_Noeud;

/** R_obtenirScore obtient le score d'un résultat.*/
unsigned int R_obtenirScore (Resultat resultat);
/** R_obtenirMot obtient le mot d'un résultat.*/
Mot R_obtenirMot (Resultat resultat);
/** L_listeChainee crée une liste chainée vide.*/
ListeChainee L_listeChainee ();
/** L_estVide permet de savoir si une ListeChainee est vide.*/
Booleen L_estVide (ListeChainee l);
/** L_ajouterEnTete ajoute en tete de la liste chainée le resultat.*/
void L_ajouterEnTete (ListeChainee* pl, Resultat resultat);
/** L_obtenirResultat obtient le résultat lié à la liste.*/
Resultat L_obtenirResultat (ListeChainee l);
/** L_obtenirListeSuivante obtient la liste chainée suivante.*/
ListeChainee L_obtenirListeSuivante (ListeChainee l);
/** L_fixerElement permet de fixer un résultat.*/
void L_fixerElement (ListeChainee* pl, Resultat resultat);
/** L_fixerListeSuivante permet de fixer une liste suivante.*/
void L_fixerListeSuivante (ListeChainee* pl, ListeChainee suivant);
/** L_afficher permet d' afficher les resultats d'une liste chainée (mot et score).*/
void L_afficher (ListeChainee l);
/** L_supprimerTete permet de supprimer la tete d'une liste chainee. */
void L_supprimerTete (ListeChainee* pl);
/** L_supprimer permet de supprimer une liste chainee. */
void L_supprimer (ListeChainee* pl);
/** L_insertion permet d'inserer des cases Contigues dans une liste au respectant
* l'ordre croissant des scores.*/
void L_insertion (ListeChainee* liste, CasesContigues casesContigues);
/** L_estPresent permet de savoir si une un mot est présent dans la liste */
Booleen L_estPresent (ListeChainee* Liste, Mot mot);
#endif
