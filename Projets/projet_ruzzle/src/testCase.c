#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Case.h"
#include "Booleen.h"

int init_suite_success (void) {
  return 0;
}

int clean_suite_success (void) {
  return 0;
}

void test_C_obtenirNbPoints (void){
  Case uneCase;
  uneCase = C_initialisationCase ('a',1,'L'+'D',TRUE);
  CU_ASSERT_TRUE (C_obtenirNbPoints (uneCase) == 1);
}

void test_C_obtenirLettre (void){
  Case uneCase;
  uneCase = C_initialisationCase ('a',1,'L'+'D',TRUE);
  CU_ASSERT_TRUE (C_obtenirLettre (uneCase) == 'a');
}

void test_C_obtenirBonus (void){
  Case uneCase;
  uneCase = C_initialisationCase ('a',1,'L'+'D',TRUE);
  CU_ASSERT_TRUE (C_obtenirBonus (uneCase) == 'L'+'D');
}

void test_C_estDejaUtilisee (void){
  Case uneCase;
  uneCase = C_initialisationCase ('a',1,'L'+'D',TRUE);
  CU_ASSERT_TRUE (C_estDejaUtilisee (uneCase) == TRUE);
}

void test_C_sontEgales (void){
  Case uneCase1, uneCase2;
  uneCase1 = C_initialisationCase('a',1,'L'+'D',TRUE);
  uneCase2 = C_initialisationCase('a',1,'L'+'D',TRUE);
  CU_ASSERT_TRUE (C_sontEgales (uneCase1,uneCase2) == TRUE);
}

void test_C_bonusLettreEnNaturel (void){
  Case uneCase;
  uneCase = C_initialisationCase ('a',1,'L'+'D',TRUE);
  CU_ASSERT_TRUE (C_bonusLettreEnNaturel (uneCase) == 2);
}

void test_C_bonusMotEnNaturel (void){
  Case uneCase;
  uneCase = C_initialisationCase ('a',1,'L'+'D',TRUE);
  CU_ASSERT_TRUE (C_bonusMotEnNaturel (uneCase)==1);
}


int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : Case", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

/* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "obtenir nombre de points", test_C_obtenirNbPoints))
      || (NULL == CU_add_test(pSuite, "obtenir la lettre", test_C_obtenirLettre))
      || (NULL == CU_add_test(pSuite, "obtenir le bonus", test_C_obtenirBonus))
      || (NULL == CU_add_test(pSuite, "est deja utilisé", test_C_estDejaUtilisee))
      || (NULL == CU_add_test(pSuite, "transformer le bonus de la lettre en naturel", test_C_bonusLettreEnNaturel))
      || (NULL == CU_add_test(pSuite, "transformer le bonus du mot en naturel", test_C_bonusMotEnNaturel))
      || (NULL == CU_add_test(pSuite, "sont egale", test_C_sontEgales))
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
