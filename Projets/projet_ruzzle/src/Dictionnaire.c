#include "Dictionnaire.h"
#include <assert.h>
#include <stdio.h>

/* Le type dictionnaire est une spécialisation du type ArbreBinaireDeLettres puisqu'on ne gère plus que des Lettres mais des Mots.
 * De plus, et c'est fondamentale, les lettres sont ordonnées dans l'ordre alphabétique
 * Pour plus de détailles voir le rapport */

char DICO_obtenirLaLettre (Dictionnaire dico){
	// getter classique
	assert (!DICO_estVide(dico));
	return L_obtenirLaLettre (ABDL_obtenirLettre (dico));
}

Booleen DICO_obtenirEstFinMot (Dictionnaire dico){
	// getter classique
	assert (!DICO_estVide(dico));
	return L_obtenirEstFinDeMot(ABDL_obtenirLettre(dico));
}

void DICO_fixerLaLettre (Dictionnaire dico, char lettre){
	// setter classique
	Lettre temp = ABDL_obtenirLettre (dico);
	L_fixerLaLettre (&temp,lettre);
	ABDL_fixerLettre (dico,temp);
}

void DICO_fixerFinMot (Dictionnaire dico, Booleen finDeMot){
	// setter classique
	Lettre temp = ABDL_obtenirLettre (dico);
	L_fixerFinDeMot (&temp,finDeMot);
	ABDL_fixerLettre (dico,temp);
}

Dictionnaire DICO_dictionnaire (){
	return ABDL_arbreBinaireDeLettres ();
}

Booleen DICO_estVide (Dictionnaire dico){
	return ABDL_estVide (dico);
}

Booleen DICO_estPresent (Dictionnaire dico, Mot unMot){
	/* On recherche les lettres d'un mot les unes après les autres dans le dictionnaire et on cherche si la dernière lettre marque une fin de mot*/
	unsigned int i = 0;
	while (!DICO_estVide (dico)) {
		if (DICO_obtenirLaLettre (dico) > M_iemeLettre (unMot,i)){
			// Alors la lettre recherchée n'est pas présente du fait de l'ordre alphabétique
			return FALSE;
		} else {
			if (DICO_obtenirLaLettre(dico) == M_iemeLettre(unMot,i)){
				/* S'il s'agit de la bonne lettre 2 cas :
				 * S'il s'agit de la dernière lettre du mot, on regarde si le mot existe dans le dico via le Booleen
				 * Sinon on recherche la lettre suivante */
				if (i == (M_longeurMot(unMot) -1)){
					if (DICO_obtenirEstFinMot(dico)){
						return TRUE;
					} else {
						return FALSE;
					}
				} else {
					dico = ABDL_obtenirFilsGauche(dico);
					i++;
				}
			} else {
				// Sinon la lettre de la racine du dico n'est pas bonne, on continue de la chercher
				dico = ABDL_obtenirFilsDroit(dico);
			}
		}
	}
	return FALSE;
}

void DICO_insererMotRecursif (Dictionnaire* pdico, Mot unMot, unsigned int position){
	/* Permet d'inserer à sa place un mot dans le dictionnaire */
	Dictionnaire temp, temp2;
	if (DICO_estVide (*pdico)) {
		/* Si le dictionnaire est vide on insère un Noeud contenant la lettre mais pas de fils grace à ABDL_ajouterRacine */
		if (position < (M_longeurMot(unMot)-1)) {
			// Cas où il ne s'agit pas de la dernière lettre
			(*pdico) = ABDL_ajouterRacine (M_iemeLettre (unMot,position),FALSE,ABDL_arbreBinaireDeLettres (),ABDL_arbreBinaireDeLettres());
			temp = ABDL_obtenirFilsGauche (*pdico);
			// On insère alors la lettre suivante
			DICO_insererMotRecursif	(&temp,unMot,(position+1));
			ABDL_fixerFilsGauche (*pdico,temp);
		} else {
			// Cas où il s'agit de la dernière lettre, la récursion s'achève
			(*pdico) = ABDL_ajouterRacine (M_iemeLettre(unMot,position),TRUE,ABDL_arbreBinaireDeLettres(),ABDL_arbreBinaireDeLettres());
		}
	} else {
		/* Si le dictionnaire n'est pas vide alors on doit trouver la bonne place
		 * Soit la lettre est avant celle de la racine du dico et il suffit d'ajouter une racine : */
		if (M_iemeLettre(unMot,position) < DICO_obtenirLaLettre(*pdico)){
			if (position < (M_longeurMot(unMot)-1)) {
				(*pdico) = ABDL_ajouterRacine (M_iemeLettre(unMot,position),FALSE,ABDL_arbreBinaireDeLettres(),*pdico);
				temp = ABDL_obtenirFilsGauche (*pdico);
				DICO_insererMotRecursif	(&temp,unMot,(position+1));
				ABDL_fixerFilsGauche (*pdico,temp);
			} else {
				(*pdico) = ABDL_ajouterRacine (M_iemeLettre(unMot,position),TRUE,ABDL_arbreBinaireDeLettres(),*pdico);
			}
		} else {
			/* Soit on se déplace dans le dictionnaire jusqu'à être à la bonne place */
			temp = (*pdico);
			Booleen mauvaisePosition = TRUE;
			while ((M_iemeLettre(unMot,position) != DICO_obtenirLaLettre(temp)) && mauvaisePosition && (!DICO_estVide(ABDL_obtenirFilsDroit(temp)))) {
				mauvaisePosition = (M_iemeLettre(unMot,position) >= DICO_obtenirLaLettre(ABDL_obtenirFilsDroit(temp)));
				if (mauvaisePosition) {
					temp = ABDL_obtenirFilsDroit (temp);
				}
			}
			if (M_iemeLettre(unMot,position) == DICO_obtenirLaLettre(temp)){
				/* Si la lettre est déjà présente alors on insère la lettre suivante s'il y en a */
				if (position < (M_longeurMot(unMot)-1)){
					temp2 = ABDL_obtenirFilsGauche (temp);
					DICO_insererMotRecursif	(&temp2,unMot,(position+1));
					ABDL_fixerFilsGauche (temp,temp2);
				} else {
					/* Si il n'y a pas de lettre suivante on fixe la fin du mot à vrai et la recursion s'achève */
					DICO_fixerFinMot (temp,TRUE);
				}
			} else {
				/* Sinon si la lettre n'est pas présente, il faut l'ajouter et passer à la suivante toujours si elle existe sinon ... */
				if (position < (M_longeurMot(unMot)-1)) {
					temp2 = ABDL_ajouterRacine (M_iemeLettre(unMot,position),FALSE,ABDL_arbreBinaireDeLettres(),ABDL_obtenirFilsDroit(temp));
					ABDL_fixerFilsDroit (temp,temp2);
					temp = ABDL_obtenirFilsGauche (temp2);
					DICO_insererMotRecursif	(&temp,unMot,(position+1));
					ABDL_fixerFilsGauche (temp2,temp);
				} else {
					temp2 = ABDL_ajouterRacine (M_iemeLettre(unMot,position),TRUE,ABDL_arbreBinaireDeLettres(),ABDL_obtenirFilsDroit(temp));
					ABDL_fixerFilsDroit (temp,temp2);
				}
			}
		}
	}
}

void DICO_insererMot (Dictionnaire* dico, Mot unMot){
	/* Appelle DICO_insererMotRecursif sur la première lettre du mot pour inserer ce dernier dans le dictionnaire */
	if (!DICO_estPresent (*dico,unMot)) {
		DICO_insererMotRecursif (dico,unMot,0);
	}
}

Booleen DICO_estUnPrefixe (Dictionnaire dico, Mot unMot){
	/* Ressemble à DICO_estPresent sauf que l'on veut que le Noeud contenant la dernière lettre ait au moins un fils */
	unsigned int i = 0;
	while (!DICO_estVide (dico)){
		if (DICO_obtenirLaLettre (dico) > M_iemeLettre (unMot,i)){
			return FALSE;
		} else {
			if (DICO_obtenirLaLettre (dico) == M_iemeLettre (unMot,i)){
				if (i == (M_longeurMot (unMot) -1)){
					if (!DICO_estVide (ABDL_obtenirFilsGauche (dico))){
						return TRUE;
					} else {
						return FALSE;
					}
				} else {
					dico = ABDL_obtenirFilsGauche (dico);
					i++;
				}
			} else {
				dico = ABDL_obtenirFilsDroit (dico);
			}
		}
	}
	return FALSE;
}

void DICO_supprimer (Dictionnaire* dico){
	ABDL_supprimer (dico);
}
