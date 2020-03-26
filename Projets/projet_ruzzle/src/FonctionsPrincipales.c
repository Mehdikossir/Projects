#include <stdio.h>
#include "FonctionsPrincipales.h"

void chargerLeDictionnaire (Dictionnaire* pdico, FILE* fic){
	char info[4] = "";
	Dictionnaire temp = DICO_dictionnaire ();
	/* Si on est pas au bout du fichier on créér une racine contenant les informations lues et on relance la récursion sur le fils gauche puis le droit */
	if (fgets(info,4,fic) != NULL){
		int l = strlen (info);
		if (info[l-1] == '\n'){
			info[l-1] = '\0';
		}
		// '%' indique qu'un fils est vide, il s'agit d'une condition d'arret
		if (info[0] != '%'){
			Booleen booleen;
			if (info[1] == '0'){
				booleen = FALSE;
			} else {
				booleen = TRUE;
			}
			(*pdico) = ABDL_ajouterRacine (info[0], booleen, DICO_dictionnaire (), DICO_dictionnaire ());
			temp = ABDL_obtenirFilsGauche (*pdico);
			chargerLeDictionnaire (&temp, fic);
			ABDL_fixerFilsGauche (*pdico, temp);
			temp = ABDL_obtenirFilsDroit(*pdico);
			chargerLeDictionnaire (&temp, fic);
			ABDL_fixerFilsDroit (*pdico, temp);
		}
	}
}

Grille initialiserGrille (char* chaineDeCaractereDecrivantLaGrille) {
    Case tempCase;
    Bonus bonus; Grille grille; unsigned int nbPoints;Coordonnee coordonnee;
    unsigned int x,y;
    grille = G_grille ();
	/*transformation de la chaine de caractères avec des espaces*/
	for(int i = 0; i<=65;i++){
		if (chaineDeCaractereDecrivantLaGrille[i] == ' '){
			chaineDeCaractereDecrivantLaGrille[i] = 'V';
			chaineDeCaractereDecrivantLaGrille[i+1] = 'D';
		}
	}
	/*transformation des majuscules en minuscules*/
	for (int i = 0; i < 16; i++){
		if (chaineDeCaractereDecrivantLaGrille [4*i] < 91){
			chaineDeCaractereDecrivantLaGrille [4*i] = chaineDeCaractereDecrivantLaGrille [4*i] + 32;
		}
	}
	for (int i = 0; i < 16; i++){
		x = i / 4;
		y = i % 4;
		coordonnee.x = x; coordonnee.y = y;
		nbPoints = chaineDeCaractereDecrivantLaGrille [(i*4)+1] - 48;
		bonus = chaineDeCaractereDecrivantLaGrille [(i*4)+2] + chaineDeCaractereDecrivantLaGrille [(i*4)+3];
		tempCase = C_initialisationCase (chaineDeCaractereDecrivantLaGrille[4*i], nbPoints, bonus, FALSE);
		G_modifierCase (grille,tempCase,coordonnee);
    }
    return grille;
}

void rechercheDeMot (Grille grille, Coordonnee coordonnee, CasesContigues casesContigues, ListeChainee *resultat, Dictionnaire dico){
  CC_ajouterCase (&casesContigues, G_obtenirCase (grille,coordonnee));
	G_changementDEtat (grille,coordonnee);

	if (CC_longueur (casesContigues) > 1){
		if ((DICO_estPresent (dico, CC_casesContiguesEnMot (casesContigues)))){
			L_insertion (resultat,casesContigues);
  	}
	}

  unsigned int i = coordonnee.x; unsigned int j = coordonnee.y;
  for (int dx = (i <= 0 ? 0 : -1); dx <= (i >= 3 ? 0 : 1); dx++){
			for (int dy = (j <= 0 ? 0 : -1); dy <= (j >= 3 ? 0 : 1); dy++){
        Coordonnee coordonneeBoucle; coordonneeBoucle.x = dx + i; coordonneeBoucle.y = dy + j;
        if((!C_estDejaUtilisee (G_obtenirCase(grille, coordonneeBoucle))) &&
				((CC_longueur (casesContigues) == 1) || (DICO_estUnPrefixe (dico, CC_casesContiguesEnMot (casesContigues))))) {
					rechercheDeMot (grille, coordonneeBoucle, casesContigues, resultat, dico);
      }
  	}
	}
	CC_supprimerTeteCase (&casesContigues);
	G_changementDEtat (grille,coordonnee);
}

ListeChainee ruzzleSolveur (Grille grille, Dictionnaire dico){
  ListeChainee resultat = L_listeChainee();
  Coordonnee coordonnee;
	
	for(int i = 0;i<4;i++){
    for(int j= 0;j<4;j++){
        coordonnee.x = i; coordonnee.y =j;
				CasesContigues casesContigues = CC_casesContigues ();
				rechercheDeMot(grille, coordonnee, casesContigues, &resultat, dico);
				CC_supprimer(&casesContigues);
		}
  }
  return resultat;
}
