#ifndef __ABDL__
#define __ABDL__

#include "Booleen.h"

/** Le type Lettre est une structure contenant une lettre et un booleen qui indique si cette lettre marque la fin du mot*/

typedef struct {
	        char laLettre;
	     Booleen finDeMot;
} Lettre;

/** L_obtenirLaLettre retourne le caractère*/
char L_obtenirLaLettre (Lettre uneLettre);
/** L_obtenirEstFinDeMot retourne le booleen*/
Booleen L_obtenirEstFinDeMot (Lettre uneLettre);
/** L_fixerLaLettre fixe le caractère*/
void L_fixerLaLettre (Lettre* uneLettre, char lettre);
/** L_fixerFinDeMot fixe le booleen*/
void L_fixerFinDeMot (Lettre* uneLettre, Booleen finMot);

/** Un ArbreBinaireDeLettres est un arbre binaire comme vu en cours contenant des Lettres*/
typedef struct ABDL_Noeud* ArbreBinaireDeLettres;
typedef struct ABDL_Noeud {
	                 Lettre lElement;
	  ArbreBinaireDeLettres filsGauche;
	  ArbreBinaireDeLettres filsDroit;
} ABDL_Noeud;

/** ABDL_arbreBinaireDeLettres retourne un arbre vide*/
ArbreBinaireDeLettres ABDL_arbreBinaireDeLettres ();
/** ABDL_estVide renvoie un booleen indiquant si l'arbre est vide*/
Booleen ABDL_estVide (ArbreBinaireDeLettres a);
/** ABDL_obtenirLettre retourne la Lettre de la racine de l'arbre*/
Lettre ABDL_obtenirLettre (ArbreBinaireDeLettres a);
/** ABDL_fixerLettre fixe la Lettre de la racine de l'arbre*/
void ABDL_fixerLettre (ArbreBinaireDeLettres a, Lettre e);
/** ABDL_obtenirFilsGauche retourne le fils gauche de l'arbre*/
ArbreBinaireDeLettres ABDL_obtenirFilsGauche (ArbreBinaireDeLettres	a);
/** ABDL_obtenirFilsDroit retourne le fils droit de l'arbre*/
ArbreBinaireDeLettres ABDL_obtenirFilsDroit (ArbreBinaireDeLettres a);
/** ABDL_fixerFilsGauche fixe le fils gauche d'un arbre*/
void ABDL_fixerFilsGauche (ArbreBinaireDeLettres a, ArbreBinaireDeLettres ag);
/** ABDL_fixerFilsDroit fixe le fils droit d'un arbre*/
void ABDL_fixerFilsDroit (ArbreBinaireDeLettres a, ArbreBinaireDeLettres ad);
/** ABDL_ajouterRacine retourne un arbre composé des éléments en entrée, à savoir le caractère le Booleen et les deux fils*/
ArbreBinaireDeLettres ABDL_ajouterRacine (char lettre, Booleen finMot, ArbreBinaireDeLettres fg, ArbreBinaireDeLettres fd);
/** ABDL_supprimerRacine libère la racine en mémoire et retourne les deux fils*/
void ABDL_supprimerRacine (ArbreBinaireDeLettres* a, ArbreBinaireDeLettres fg, ArbreBinaireDeLettres fd);
/** ABDL_supprimer libère la totalité de l'arbre*/
void ABDL_supprimer (ArbreBinaireDeLettres* a);

#endif
