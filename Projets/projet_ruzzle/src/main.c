#include <stdio.h>
#include <stdlib.h>
#include "FonctionsPrincipales.h"
#include <errno.h>
#include <time.h>

#define MAIN_ERREUR_MEMOIRE 1;

/** Conformément à notre analyse descendante, d'abord on charge le dictionnaire
*   à partir des fichier, ensuite, on récupère la grille à partir de la ligne saisi
*   par l'utilisateur, et on ressort une liste ordonnée de mots avec leurs scores
*  respectif grace à la fonction ruzzleSolveur. Finallement on affiche le résultat obtenu */

// Exemple du prof : "T1LDR1  A1  S1MTE1LTN1  C3LTE1  U1  R1  I1  L2MDS1  O1MDP3  S1  " dico-serialise.txt


int main (int argc, char** argv) {
	long clk_tck = CLOCKS_PER_SEC;
	time_t tempsDeb, tempsFin;
	tempsDeb = clock ();
	Dictionnaire* pdico = (Dictionnaire*) malloc (sizeof(Dictionnaire));
	if (pdico != NULL) {
		errno = 0;
		(*pdico) = NULL;
		FILE* fic = NULL;
		char cheminRelatif[1000] = "include/";
		strcat (cheminRelatif,argv[2]);
		fic = fopen (cheminRelatif,"r");
		if (fic != NULL) {
			chargerLeDictionnaire (pdico,fic);
			fclose (fic);
			Grille  grille = initialiserGrille (argv[1]);
			ListeChainee liste = L_listeChainee ();
			liste = ruzzleSolveur (grille,*pdico);
			L_afficher (liste);
			DICO_supprimer (pdico);
		} else {
			printf ("Impossible d'ouvrir le fichier dico-serialise.txt\n");
		}
	} else {
		errno = MAIN_ERREUR_MEMOIRE;
	}
	free (pdico);
	tempsFin = clock ();
	printf ("\n");
	printf ("Temps consomme (s) : %lf \n",(double)(tempsFin-tempsDeb)/(double)clk_tck);
	return 0;
}
