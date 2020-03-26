#include<stdlib.h>
#include<CUnit/Basic.h>
#include "Mot.h"
#define TRUE 1
#define FALSE 0

int init_suite_success (void){
  return 0;
}

int clean_suite_success (void){
  return 0;
}
void test_M_Mot (void){
  Mot mot1 = "ba";
  Mot mot2 = M_mot ('b','a');
  CU_ASSERT_TRUE (M_sontEgaux (mot1,mot2) == TRUE);
}

void test_M_est_Caractere_Special (void){
  char car = '#';
  CU_ASSERT_TRUE (M_estCaractereSpecial (car) == TRUE);
}

void test_M_est_Un_Mot (void){
  char chaine[] = "Mehdi";
  CU_ASSERT_TRUE (M_estUnMot (chaine) == TRUE);
}

void test_M_Sont_Egaux (void){
  Mot mot = "Mehdi";
  CU_ASSERT_TRUE (M_sontEgaux (mot,mot) == TRUE);
}

void test_M_allonger_Mot (void){
  Mot mot = "mehdi";
  char lettre = 'k';
  CU_ASSERT_TRUE (M_sontEgaux (M_allongerMot (mot,lettre), "mehdik") == TRUE);
}

void test_M_chaine_en_mot (void){
  char chaine[] = "mehdi";
  CU_ASSERT_TRUE (M_sontEgaux (M_chaineEnMot (chaine), chaine) == TRUE);
}


void test_M_longeur_mot (void){
Mot mot = "Mehdi";
  CU_ASSERT_TRUE (M_longeurMot (mot) == 5);
}

void test_M_ieme_lettre (void){
Mot mot = "Mehdi";
  CU_ASSERT_TRUE (M_iemeLettre (mot,3) == 'd');
}

void test_M_est_en_ordre_alphabetique (void){
Mot Mot1 = "Mehdi";
Mot Mot2 = "messi";
  CU_ASSERT_TRUE (M_estEnOrdreAlphabetique (Mot1,Mot2) == TRUE);
}
void test_M_transformer_Mot_Maj_en_Min (void){
Mot Mot1 = "MeHDi";
Mot Mot2 = "mehdi";
  CU_ASSERT_TRUE (M_sontEgaux ((M_transformerMotMajenMin(Mot1)),Mot2)==TRUE);
}


int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : mot", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

/* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "est Cractere Special", test_M_est_Caractere_Special))
  || (NULL == CU_add_test(pSuite, "M Mot", test_M_Mot))
      || (NULL == CU_add_test(pSuite, "est Un Mot", test_M_est_Un_Mot))
      || (NULL == CU_add_test(pSuite, "Sont Egaux", test_M_Sont_Egaux))
      || (NULL == CU_add_test(pSuite, "Allonger Mot", test_M_allonger_Mot))
      || (NULL == CU_add_test(pSuite, "Chaine en mot", test_M_chaine_en_mot))
      || (NULL == CU_add_test(pSuite, "Longeur Mot", test_M_longeur_mot))
      || (NULL == CU_add_test(pSuite, "ieme Lettre", test_M_ieme_lettre))
      || (NULL == CU_add_test(pSuite, "Est en ordre Alphabetique", test_M_est_en_ordre_alphabetique))
      || (NULL == CU_add_test(pSuite, "transformer maj en min", test_M_transformer_Mot_Maj_en_Min))
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
