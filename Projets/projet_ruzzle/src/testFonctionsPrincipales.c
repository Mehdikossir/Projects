#include <stdlib.h>
#include <CUnit/Basic.h>
#include "FonctionsPrincipales.h"

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

// ligne de test à taper pour les tests :
// A1  a2LDB3LTb4MDX5MTX6  X7LDX8LTX9MDX1MTX2  X3LDX4LTX5MDz6MTZ7MD
void test_initialiserGrille(char* chaineDeCaractereDecrivantLaGrille){
  Grille grille;
  Case uneCase1;
  Coordonnee coordonnee;
  coordonnee.x = 0;
  coordonnee.y = 3;
  uneCase1.lettre = 'D';
  uneCase1.nbPoints = 4;
  uneCase1.bonus = 'M'+'D';
  uneCase1.dejaUtilisee = FALSE;
  grille = initialiserGrille (chaineDeCaractereDecrivantLaGrille);
  CU_ASSERT_TRUE (C_sontEgales (G_obtenirCase (grille,coordonnee), uneCase1));
}

void test_chargerLeDictionnaire () {
	Dictionnaire* pdico = (Dictionnaire*) malloc (sizeof(Dictionnaire));
	if (pdico != NULL) {
		(*pdico) = NULL;
		FILE* fic = NULL;
		fic = fopen("include/dico-serialise.txt","r");
		if (fic != NULL) {
			chargerLeDictionnaire (pdico,fic);
			fclose (fic);
			CU_ASSERT_TRUE (DICO_estUnPrefixe (*pdico, M_chaineEnMot("abai")) && (!DICO_estPresent(*pdico,M_chaineEnMot("aba"))));
			DICO_supprimer (pdico);
		} else {
			printf ("Impossible d'ouvrir le fichier dico-serialise.txt\n");
		}
	}
	free (pdico);
}

int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : Fonctions Principales", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

/* Ajout des tests à la suite de tests boite noire */
  if (/*(NULL == CU_add_test(pSuite, "initialisation de la Grille", test_initialiserGrille))
	  || */(NULL == CU_add_test(pSuite, "charger dico", test_chargerLeDictionnaire))
	 )
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* Lancement des tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");

  /* Nettoyage du registre */
  CU_cleanup_registry();
  return CU_get_error();
}
