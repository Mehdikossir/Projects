#include "serialiserDico.h"
#define MAX 30 // On suppose que les mots ne dépasse pas cette taille (le plus long mot de la langue francaise est de 26 lettres)
/* On ne cherche à stocker que des mots dont la taille est comprise entre 2 et 16 lettres car cela correspond aux contraintes du jeu ruzzle */
#define TAILLEMIN 2
#define TAILLEMAX 16

/* Permet de créer un dictionnaire à partir d'un fichier tel que dico-ref-ascii-sans-accent.txt */
Dictionnaire creerDictionnaire (FILE* fic){
	Dictionnaire dico = DICO_dictionnaire ();
	char temp[MAX] = "";
	Mot mot;
	/* On lit un mot jusqu'à la fin du fichier */
	while (fgets(temp,MAX,fic) != NULL){
		int l = strlen (temp);
		if (temp[l-1] == '\n'){
			temp[l-1] = '\0';
		}
		if (M_estUnMot (temp)){
			/* Si il n'y a pas de caractère spéciaux et que la taille correspond alors on insère le mot tout en minuscule dans le dictionnaire */
			mot = M_chaineEnMot (temp);
			if ((M_longeurMot (mot) >= TAILLEMIN) && (M_longeurMot (mot) <= TAILLEMAX)) {
				DICO_insererMot (&dico,M_transformerMotMajenMin(mot));
			}
		}
	}
	return dico;
}

/* Permet de sérialiser un dictionnaire pour pouvoir le recharger efficacement.
 * Pour plus de détails voir le rapport */
void serialiserDictionnaire (FILE* fic, Dictionnaire unDico){
	Dictionnaire temp = DICO_dictionnaire ();
	Lettre element;
	if (!DICO_estVide (unDico)){
		element = ABDL_obtenirLettre (unDico);
		char finDeMot;
		if (L_obtenirEstFinDeMot (element) == TRUE){
			finDeMot = '1';
		} else {
			finDeMot = '0';
		}
		fprintf (fic,"%c%c\n",L_obtenirLaLettre (element),finDeMot);
		if (DICO_estVide (ABDL_obtenirFilsGauche (unDico))){
			fprintf (fic,"%s\n","%(");
		}
		temp = ABDL_obtenirFilsGauche (unDico);
		serialiserDictionnaire (fic,temp);
		if (DICO_estVide (ABDL_obtenirFilsDroit (unDico))){
			fprintf (fic,"%s\n","%)");
		}
		temp = ABDL_obtenirFilsDroit (unDico);
		serialiserDictionnaire (fic,temp);
	}
}

int main() {
	FILE* fic = NULL;
	/* On crée le dictionnaire à partir du fichier dico-ref-ascii-sans-accent.txt */
	fic = fopen("include/dico-ref-ascii-sans-accent.txt","r");
	if (fic != NULL){
		Dictionnaire dico = creerDictionnaire (fic);
		fclose (fic);
		fic = fopen("include/dico-serialise.txt","w");
		if (fic != NULL){
			/* Et on le sérialise dans le fichier dico-serialise.txt */
			serialiserDictionnaire (fic,dico);
			fclose (fic);
		} else {
			printf ("Impossible d'ouvrir le fichier sérialisé\n");
		}
		DICO_supprimer (&dico);
    } else {
        printf ("Impossible d'ouvrir le fichier initial\n");
    }
    return 0;
}
