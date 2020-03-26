#ifndef __DICO__
#define __DICO__

#include "ArbreBinaireDeLettres.h"
#include "Mot.h"

/** On défine notre dictionnaire comme étant un ArbreBinaireDeLettres dont la conception et l'implémetation sont tirées du cours*/
typedef ArbreBinaireDeLettres Dictionnaire;

/** DICO_obtenirLaLettre retourne la lettre de la racine du dictionnaire*/
char DICO_obtenirLaLettre (Dictionnaire dico);
/** DICO_obtenirEstFinMot retourne un Booleen indiquant si la lettre constitue une fin de mot ou non*/
Booleen DICO_obtenirEstFinMot (Dictionnaire dico);
/** DICO_fixerLaLettre fixe la lettre de la racine*/
void DICO_fixerLaLettre (Dictionnaire dico, char lettre);
/** DICO_fixerFinMot fixe le Booleen de la racine*/
void DICO_fixerFinMot (Dictionnaire dico, Booleen finDeMot);
/** DICO_dictionnaire retourne un dictionnaire vide*/
Dictionnaire DICO_dictionnaire ();
/** DICO_estVide retourne un Booleen indiquant si le dictionnaire est vide*/
Booleen DICO_estVide (Dictionnaire dico);
/** DICO_estPresent retourne un Booleen indiquant si le mot est dans le dictionnaire*/
Booleen DICO_estPresent (Dictionnaire dico, Mot unMot);
/** DICO_insererMot insère un mot dans le dictionnaire*/
void DICO_insererMot (Dictionnaire* dico, Mot unMot);
/** DICO_estUnPrefixe retourne un Booleen indiquant si le mot en entrée est préfixe d'un autre mot contenu dans le dictionnaire*/
Booleen DICO_estUnPrefixe (Dictionnaire dico, Mot unMot);
/** DICO_supprimer libère le dictionnaire en mémoire*/
void DICO_supprimer (Dictionnaire* dico);

#endif
