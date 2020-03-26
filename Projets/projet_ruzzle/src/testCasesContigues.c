#include<stdlib.h>
#include<CUnit/Basic.h>
#include "CasesContigues.h"

int init_suite_success (void) {
  return 0;
}

int clean_suite_success (void) {
  return 0;
}

void test_CC_estVide (void){
  // initialisation de casesContigues vide
  CasesContigues desCasesContigues =  CC_casesContigues ();
  CU_ASSERT_TRUE (CC_estVide (desCasesContigues));
}

void test_CC_obtenirCase (void){
  CasesContigues desCasesContigues =  CC_casesContigues();
  Case uneCase, uneAutreCase;
  uneCase = C_initialisationCase ('A',1,'V'+'D',FALSE);
  CC_ajouterCase (&desCasesContigues, uneCase);
  uneAutreCase = CC_obtenirCase (desCasesContigues);
  CU_ASSERT_TRUE (C_sontEgales (uneCase,uneAutreCase));
}


void test_CC_estPresent (void){
  CasesContigues desCasesContigues =  CC_casesContigues ();
  Case uneCase = C_initialisationCase ('A',1,'V'+'D',FALSE);
  CC_ajouterCase (&desCasesContigues, uneCase);
  CU_ASSERT_TRUE (CC_estPresent (desCasesContigues,uneCase));
}

void test_CC_ajouterCase (void){
  CasesContigues desCasesContigues =  CC_casesContigues ();
  Case uneCase = C_initialisationCase ('A',1,'V'+'D',FALSE);
  CC_ajouterCase (&desCasesContigues, uneCase);
  CU_ASSERT_TRUE (!CC_estVide (desCasesContigues));
}

void test_CC_longueur (void){
  CasesContigues desCasesContigues =  CC_casesContigues ();
  CU_ASSERT_TRUE (CC_longueur (desCasesContigues) == 0);
}

void test_CC_scoreCasesContiguesSansBonusMot (void){
  CasesContigues desCasesContigues; Case case1, case2;
  desCasesContigues =  CC_casesContigues();
  case1 = C_initialisationCase ('i',2,'V'+'D',FALSE);
  case2 = C_initialisationCase ('l',4,'V'+'D',FALSE);
  CC_ajouterCase (&desCasesContigues, case1);
  CC_ajouterCase (&desCasesContigues, case2);
  CU_ASSERT_TRUE (CC_scoreCasesContiguesSansBonusMot (desCasesContigues) == 6);
}

void test_CC_scoreCasesContigues(void){
  CasesContigues desCasesContigues; Case case1, case2;
  desCasesContigues =  CC_casesContigues();
  case1 = C_initialisationCase ('i',2,'M'+'D',FALSE);
  case2 = C_initialisationCase ('l',4,'V'+'D',FALSE);
  CC_ajouterCase (&desCasesContigues, case1);
  CC_ajouterCase (&desCasesContigues, case2);
  CU_ASSERT_TRUE (CC_scoreCasesContigues (desCasesContigues)==12);
}


void test_CC_casesContiguesEnMot (void){
  Mot mot1, mot2; CasesContigues desCasesContigues; Case case1, case2, case3, case4;
  mot1 = M_mot ('e','l');
  mot1 = M_allongerMot (mot1,'l');
  mot1 = M_allongerMot (mot1,'e');
  desCasesContigues =  CC_casesContigues ();
  case1 = C_initialisationCase ('e',2,'V'+'D',FALSE);
  case2 = C_initialisationCase ('l',4,'V'+'D',FALSE);
  case3 = C_initialisationCase ('l',4,'V'+'D',FALSE);
  case4 = C_initialisationCase ('e',2,'V'+'D',FALSE);
  CC_ajouterCase (&desCasesContigues, case1);
  CC_ajouterCase (&desCasesContigues, case2);
  CC_ajouterCase (&desCasesContigues, case3);
  CC_ajouterCase (&desCasesContigues, case4);
  mot2 = CC_casesContiguesEnMot (desCasesContigues);
  printf("\n mot1 %s\n", mot1 );
  printf("mot2 %s\n", mot2 );
  CU_ASSERT_TRUE (M_sontEgaux (mot1, mot2));
}

void test_CC_supprimerTeteCase (void){
  CasesContigues desCasesContigues =  CC_casesContigues ();
  Case uneCase = C_initialisationCase ('A',1,'V'+'D',FALSE);
  CC_ajouterCase (&desCasesContigues, uneCase);
  CC_supprimerTeteCase (&desCasesContigues);
  CU_ASSERT_TRUE (CC_estVide (desCasesContigues));
}

void test_CC_supprimer (void){
  CasesContigues desCasesContigues =  CC_casesContigues ();
  Case uneCase = C_initialisationCase ('A',1,'V'+'D',FALSE);
  CC_ajouterCase (&desCasesContigues, uneCase);
  CC_ajouterCase (&desCasesContigues, uneCase);
  CC_supprimer (&desCasesContigues);
  CU_ASSERT_TRUE (CC_estVide (desCasesContigues));
}



int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : casesContigues", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

/* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "est vide", test_CC_estVide))
    || (NULL == CU_add_test(pSuite, "test longueur", test_CC_longueur))
    || (NULL == CU_add_test(pSuite, "test ajouter case", test_CC_ajouterCase))
    || (NULL == CU_add_test(pSuite, "test de présence", test_CC_estPresent))
    || (NULL == CU_add_test(pSuite, "test de obtention de case", test_CC_obtenirCase))
    || (NULL == CU_add_test(pSuite, "test de suppression de case en tete", test_CC_supprimerTeteCase))
    || (NULL == CU_add_test(pSuite, "test de suppression", test_CC_supprimer))
    || (NULL == CU_add_test(pSuite, "test de transformation des Cases contigues en mot", test_CC_casesContiguesEnMot))
    || (NULL == CU_add_test(pSuite, "test du score des Cases contigues sans bonus mot", test_CC_scoreCasesContiguesSansBonusMot))
    || (NULL == CU_add_test(pSuite, "test du score des Cases contigues avec bonus mot", test_CC_scoreCasesContigues))
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
