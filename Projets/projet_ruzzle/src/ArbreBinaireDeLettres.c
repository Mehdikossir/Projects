#include "ArbreBinaireDeLettres.h"
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

#define ABDL_ERREUR_MEMOIRE 1;

/* La conception et l'implémentation de ArbreBinaireDeLettres est reprise en grande partie directement du cours
 * il n'y a donc pas beaucoup de commentaire */

char L_obtenirLaLettre (Lettre uneLettre) {
	// getter classique
	errno = 0;
	return uneLettre.laLettre;
}

Booleen L_obtenirEstFinDeMot (Lettre uneLettre) {
	// getter classique
	errno = 0;
	return uneLettre.finDeMot;
}

void L_fixerLaLettre (Lettre* uneLettre, char lettre) {
	// setter classique
	errno = 0;
	(*uneLettre).laLettre = lettre;
}

void L_fixerFinDeMot (Lettre* uneLettre, Booleen finMot) {
	// setter classique
	errno = 0;
	(*uneLettre).finDeMot = finMot;
}

ArbreBinaireDeLettres ABDL_arbreBinaireDeLettres () {
	// retourne un pointeur sur NULL <=> arbre vide
	errno = 0;
	return NULL;
}

Booleen ABDL_estVide (ArbreBinaireDeLettres a) {
	errno = 0;
	return a == NULL;
}

Lettre ABDL_obtenirLettre (ArbreBinaireDeLettres a) {
	// getter classique
	assert (!(ABDL_estVide (a)));
	errno = 0;
	return (*a).lElement;
}

void ABDL_fixerLettre (ArbreBinaireDeLettres a, Lettre e) {
	// setter classique
	assert (!(ABDL_estVide (a)));
	errno = 0;
	(*a).lElement = e;
}

ArbreBinaireDeLettres ABDL_obtenirFilsGauche (ArbreBinaireDeLettres	a) {
	// getter classique
	assert (!(ABDL_estVide (a)));
	errno = 0;
	return (*a).filsGauche;
}

ArbreBinaireDeLettres ABDL_obtenirFilsDroit (ArbreBinaireDeLettres a) {
	// getter classique
	assert (!(ABDL_estVide (a)));
	errno = 0;
	return (*a).filsDroit;
}

void ABDL_fixerFilsGauche (ArbreBinaireDeLettres a, ArbreBinaireDeLettres ag) {
	// setter classique
	assert (!(ABDL_estVide (a)));
	errno = 0;
	(*a).filsGauche = ag;
}

void ABDL_fixerFilsDroit (ArbreBinaireDeLettres a, ArbreBinaireDeLettres ad) {
	// setter classique
	assert (!(ABDL_estVide (a)));
	errno = 0;
	(*a).filsDroit =ad;
}

ArbreBinaireDeLettres ABDL_ajouterRacine (char lettre, Booleen finMot, ArbreBinaireDeLettres fg, ArbreBinaireDeLettres fd) {
	/* Allocation mémoire */
	ArbreBinaireDeLettres temp = (ArbreBinaireDeLettres)malloc(sizeof(ABDL_Noeud));
	Lettre structTemp;
	/* Si allocation réussie */
	if (temp != NULL) {
		 errno = 0;
    L_fixerLaLettre	(&structTemp,lettre);
    L_fixerFinDeMot (&structTemp,finMot);
		ABDL_fixerLettre (temp,structTemp);
		ABDL_fixerFilsGauche (temp,fg);
		ABDL_fixerFilsDroit (temp,fd);
	/* Si allocation échouée */
	} else {
		errno = ABDL_ERREUR_MEMOIRE;
	}
	return temp;
}

void ABDL_supprimerRacine (ArbreBinaireDeLettres* a, ArbreBinaireDeLettres fg, ArbreBinaireDeLettres fd) {
	assert (!(ABDL_estVide ((*a))));
	errno = 0;
	/* On recupère les deux fils */
	fg = ABDL_obtenirFilsGauche (*a);
	fd = ABDL_obtenirFilsDroit (*a);
	/* On libère l'arbre */
	free(*a);
	(*a) = ABDL_arbreBinaireDeLettres ();
}

void ABDL_supprimer (ArbreBinaireDeLettres* a) {
	/* On libère ici l'abre de manière récursive */
	errno = 0;
	ArbreBinaireDeLettres tempg = ABDL_arbreBinaireDeLettres ();
	ArbreBinaireDeLettres tempd = ABDL_arbreBinaireDeLettres ();
	if (!(ABDL_estVide (*a))) {
		ABDL_supprimerRacine (a,tempg,tempd);
		ABDL_supprimer (&tempg);
		ABDL_supprimer (&tempd);
	}
}
