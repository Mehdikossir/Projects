#include<stdlib.h>
#include<CUnit/Basic.h>
#include "Grille.h"
#define TRUE 1
#define FALSE 0

int init_suite_success (void){
  return 0;
}

int clean_suite_success (void){
  return 0;
}

void test_G_grille (void){
  Case c = C_initialisationCase ('a',1,' ',FALSE);
  Grille grille = G_grille ();
  CU_ASSERT_TRUE (C_sontEgales (grille[0][0],c));

}

void test_G_obtenirCase(void){
  Grille grille = G_grille();
  Coordonnee coordonne;
  coordonne.x = 0;
  coordonne.y = 0;
  CU_ASSERT_TRUE (C_sontEgales (G_obtenirCase (grille,coordonne), grille[0][0]));
}

void test_G_modifierCase (void){
  Grille grille = G_grille();
  Coordonnee coordonnee;
  Case uneCase;
  uneCase.lettre = 'x';
  uneCase.nbPoints = 9;
  uneCase.bonus = MT;
  uneCase.dejaUtilisee = TRUE;
  coordonnee.x = 0;
  coordonnee.y = 0;
  G_modifierCase (grille,uneCase,coordonnee);
  CU_ASSERT_TRUE (C_sontEgales (uneCase,grille[0][0]));
}

void test_G_changementDEtat (void){
  Grille grille = G_grille();
  Coordonnee coordonne;
  coordonne.x = 0;
  coordonne.y = 0;
  G_changementDEtat (grille, coordonne);
  CU_ASSERT_TRUE (grille[0][0].dejaUtilisee == TRUE);
}

int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests Grille ", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, " Grille", test_G_grille))
      || (NULL == CU_add_test(pSuite, "Obtenir case", test_G_obtenirCase))
      || (NULL == CU_add_test(pSuite, "Changement D Etat", test_G_changementDEtat))
      || (NULL == CU_add_test(pSuite, "Modifier une case", test_G_modifierCase))
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
