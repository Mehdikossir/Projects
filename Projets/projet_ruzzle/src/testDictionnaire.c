#include<stdlib.h>
#include<CUnit/Basic.h>
#include "Dictionnaire.h"

int init_suite_success (void){
  return 0;
}

int clean_suite_success (void){
  return 0;
}

void test_DICO_dictionnaire (){
	Dictionnaire dico = DICO_dictionnaire ();
	CU_ASSERT_TRUE (dico == NULL);
}

void test_DICO_estVide (){
	Dictionnaire dico = DICO_dictionnaire ();
	CU_ASSERT_TRUE (DICO_estVide(dico) == TRUE);
}

void test_DICO_obtenirLaLettre (){
	Dictionnaire dico = ABDL_ajouterRacine ('a', TRUE, ABDL_arbreBinaireDeLettres(),ABDL_arbreBinaireDeLettres ());
	CU_ASSERT_TRUE (DICO_obtenirLaLettre (dico) == 'a');
	free (dico);
}

void test_DICO_obtenirEstFinMot (){
	Dictionnaire dico = ABDL_ajouterRacine ('a', TRUE, ABDL_arbreBinaireDeLettres(),ABDL_arbreBinaireDeLettres ());
	CU_ASSERT_TRUE (DICO_obtenirEstFinMot (dico) == TRUE);
	free (dico);
}

void test_DICO_fixerLaLettre (){
	Dictionnaire dico = ABDL_ajouterRacine ('a', TRUE, ABDL_arbreBinaireDeLettres(),ABDL_arbreBinaireDeLettres ());
	DICO_fixerLaLettre (dico, 'b');
	CU_ASSERT_TRUE (DICO_obtenirLaLettre (dico) == 'b');
	free (dico);
}

void test_DICO_fixerFinMot (){
	Dictionnaire dico = ABDL_ajouterRacine ('a', TRUE, ABDL_arbreBinaireDeLettres(),ABDL_arbreBinaireDeLettres ());
	DICO_fixerFinMot (dico,FALSE);
	CU_ASSERT_TRUE (DICO_obtenirEstFinMot (dico) == FALSE);
	free (dico);
}

void test_DICO_insererMot (){
	Dictionnaire* pdico = (Dictionnaire*) malloc (sizeof(Dictionnaire));
	(*pdico) = NULL;
	Mot motTest2 = M_mot ('b','d');
	DICO_insererMot (pdico,motTest2);
	Mot motTest = M_mot ('a','b');
	DICO_insererMot (pdico,motTest);
	motTest = M_allongerMot (motTest,'c');
	DICO_insererMot (pdico,motTest);
	Mot motTest3 = M_mot ('a','a');
	DICO_insererMot (pdico,motTest3);
	CU_ASSERT_TRUE ((DICO_obtenirLaLettre (*pdico) == 'a') && (DICO_obtenirLaLettre (ABDL_obtenirFilsGauche (*pdico)) == 'a') && (DICO_obtenirEstFinMot (ABDL_obtenirFilsGauche (*pdico)) == TRUE) && (DICO_obtenirLaLettre (ABDL_obtenirFilsDroit (ABDL_obtenirFilsGauche (*pdico))) == 'b') && (DICO_obtenirLaLettre (ABDL_obtenirFilsGauche (ABDL_obtenirFilsDroit (ABDL_obtenirFilsGauche(*pdico)))) == 'c') && (DICO_obtenirEstFinMot(ABDL_obtenirFilsGauche (ABDL_obtenirFilsDroit (ABDL_obtenirFilsGauche (*pdico)))) == TRUE) && (DICO_obtenirLaLettre (ABDL_obtenirFilsDroit (*pdico)) == 'b') && (DICO_obtenirLaLettre(ABDL_obtenirFilsGauche(ABDL_obtenirFilsDroit(*pdico))) == 'd'));
	DICO_supprimer (pdico);
	free (pdico);
}

void test_DICO_estPresent (){
	Dictionnaire* pdico = (Dictionnaire*) malloc (sizeof(Dictionnaire));
	(*pdico) = NULL;
	Mot motTest = M_mot ('a', 'b');
	Mot motTest2 = M_allongerMot (motTest, 'c');
	DICO_insererMot (pdico, motTest2);
	CU_ASSERT_TRUE(DICO_estPresent(*pdico, motTest2) && !DICO_estPresent (*pdico,motTest));
	DICO_supprimer (pdico);
	free (pdico);
}

void test_DICO_estUnPrefixe (){
	Dictionnaire* pdico = (Dictionnaire*) malloc (sizeof(Dictionnaire));
	(*pdico) = NULL;
	Mot motTest = M_mot ('a','b');
	Mot motTest2 = M_allongerMot (motTest,'c');
	DICO_insererMot (pdico,motTest2);
	CU_ASSERT_TRUE(DICO_estUnPrefixe (*pdico,motTest) && !DICO_estUnPrefixe(*pdico,motTest2));
	DICO_supprimer (pdico);
	free (pdico);
}


int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : Dictionnaire", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

/* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "dictionnaire vide", test_DICO_dictionnaire))
      || (NULL == CU_add_test(pSuite, "dico est vide?", test_DICO_estVide))
      || (NULL == CU_add_test(pSuite, "obtenir la lettre", test_DICO_obtenirLaLettre))
      || (NULL == CU_add_test(pSuite, "obtenir fin de mot", test_DICO_obtenirEstFinMot))
      || (NULL == CU_add_test(pSuite, "fixer la lettre", test_DICO_fixerLaLettre))
      || (NULL == CU_add_test(pSuite, "fixer fin de mot", test_DICO_fixerFinMot))
      || (NULL == CU_add_test(pSuite, "inserer mot", test_DICO_insererMot))
      || (NULL == CU_add_test(pSuite, "est présent", test_DICO_estPresent))
      || (NULL == CU_add_test(pSuite, "est un préfixe", test_DICO_estUnPrefixe))
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
