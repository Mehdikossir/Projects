#include<stdlib.h>
#include<CUnit/Basic.h>
#include "ArbreBinaireDeLettres.h"

int init_suite_success (void){
  return 0;
}

int clean_suite_success (void){
  return 0;
}

void test_L_obtenirLaLettre (){
	Lettre testStruct;
	testStruct.laLettre = 'a';
	testStruct.finDeMot = TRUE;
	CU_ASSERT_TRUE(L_obtenirLaLettre(testStruct) == 'a');
}

void test_L_obtenirEstFinDeMot (){
	Lettre testStruct;
	testStruct.laLettre = 'a';
	testStruct.finDeMot = TRUE;
	CU_ASSERT_TRUE(L_obtenirEstFinDeMot(testStruct) == TRUE);
}

void test_L_fixerLaLettre (){
	Lettre testStruct;
	testStruct.laLettre = 'a';
	testStruct.finDeMot = TRUE;
	L_fixerLaLettre(&testStruct,'b');
	CU_ASSERT_TRUE(L_obtenirLaLettre(testStruct) == 'b');
}

void test_L_fixerFinDeMot (){
	Lettre testStruct;
	testStruct.laLettre = 'a';
	testStruct.finDeMot = TRUE;
	L_fixerFinDeMot(&testStruct,FALSE);
	CU_ASSERT_TRUE(L_obtenirEstFinDeMot(testStruct) == FALSE);
}

void test_ABDL_arbreBinaireDeLettres (){
	ArbreBinaireDeLettres a = ABDL_arbreBinaireDeLettres ();
	CU_ASSERT_TRUE(a == NULL);
}

void test_ABDL_estVide (){
	ArbreBinaireDeLettres a = ABDL_arbreBinaireDeLettres ();
	CU_ASSERT_TRUE(ABDL_estVide(a) == TRUE);
}

void test_ABDL_obtenirLettre (){
	ArbreBinaireDeLettres a = ABDL_ajouterRacine ('a',TRUE,ABDL_arbreBinaireDeLettres(),ABDL_arbreBinaireDeLettres());
	CU_ASSERT_TRUE ((L_obtenirLaLettre (ABDL_obtenirLettre(a)) == 'a') && (L_obtenirEstFinDeMot (ABDL_obtenirLettre(a)) == TRUE));
	free (a);
}

void test_ABDL_fixerLettre (){
	ArbreBinaireDeLettres a = ABDL_ajouterRacine ('a',TRUE,ABDL_arbreBinaireDeLettres (), ABDL_arbreBinaireDeLettres ());
	Lettre testStruct;
	testStruct.laLettre = 'b';
	testStruct.finDeMot = FALSE;
	ABDL_fixerLettre (a, testStruct);
	CU_ASSERT_TRUE ((L_obtenirLaLettre (ABDL_obtenirLettre (a)) == 'b') && (L_obtenirEstFinDeMot (ABDL_obtenirLettre (a)) == FALSE));
	free (a);
}

void test_ABDL_obtenirFilsGauche (){
	ArbreBinaireDeLettres a = ABDL_ajouterRacine ('a',TRUE,ABDL_arbreBinaireDeLettres (), ABDL_arbreBinaireDeLettres());
	ArbreBinaireDeLettres racine = ABDL_ajouterRacine ('b',FALSE,a,ABDL_arbreBinaireDeLettres ());
	CU_ASSERT_TRUE (ABDL_obtenirFilsGauche (racine) == a);
	free (a);
	free (racine);
}

void test_ABDL_obtenirFilsDroit (){
	ArbreBinaireDeLettres a = ABDL_ajouterRacine ('a', TRUE, ABDL_arbreBinaireDeLettres(), ABDL_arbreBinaireDeLettres ());
	ArbreBinaireDeLettres racine = ABDL_ajouterRacine ('b', FALSE, ABDL_arbreBinaireDeLettres (),a);
	CU_ASSERT_TRUE (ABDL_obtenirFilsDroit (racine) == a);
	free (a);
	free (racine);
}

void test_ABDL_fixerFilsGauche (){
	ArbreBinaireDeLettres a = ABDL_ajouterRacine ('a', TRUE, ABDL_arbreBinaireDeLettres(), ABDL_arbreBinaireDeLettres());
	ArbreBinaireDeLettres racine = ABDL_ajouterRacine ('b', FALSE, ABDL_arbreBinaireDeLettres(), ABDL_arbreBinaireDeLettres());
	ABDL_fixerFilsGauche (racine, a);
	CU_ASSERT_TRUE (ABDL_obtenirFilsGauche (racine) == a);
	free (a);
	free (racine);
}

void test_ABDL_fixerFilsDroit (){
	ArbreBinaireDeLettres a = ABDL_ajouterRacine ('a',TRUE,ABDL_arbreBinaireDeLettres(),ABDL_arbreBinaireDeLettres());
	ArbreBinaireDeLettres racine = ABDL_ajouterRacine ('b',FALSE,ABDL_arbreBinaireDeLettres(),ABDL_arbreBinaireDeLettres());
	ABDL_fixerFilsDroit (racine,a);
	CU_ASSERT_TRUE (ABDL_obtenirFilsDroit (racine) == a);
	free (a);
	free (racine);
}

void test_ABDL_ajouterRacine (){
	ArbreBinaireDeLettres a = ABDL_ajouterRacine ('a', TRUE, ABDL_arbreBinaireDeLettres (), ABDL_arbreBinaireDeLettres ());
	CU_ASSERT_TRUE ((L_obtenirLaLettre (ABDL_obtenirLettre (a)) == 'a') && (L_obtenirEstFinDeMot (ABDL_obtenirLettre (a)) == TRUE) && (ABDL_obtenirFilsGauche(a) == NULL) && (ABDL_obtenirFilsDroit(a) == NULL));
	free (a);
}

void test_ABDL_supprimerRacine (){
	ArbreBinaireDeLettres a = ABDL_ajouterRacine ('a', TRUE, ABDL_arbreBinaireDeLettres (), ABDL_arbreBinaireDeLettres ());
	ArbreBinaireDeLettres fg = ABDL_arbreBinaireDeLettres ();
	ArbreBinaireDeLettres fd = ABDL_arbreBinaireDeLettres ();
	ABDL_supprimerRacine ((&a), fd, fg);
	CU_ASSERT_TRUE (a == NULL);
	free (a);
	free (fg);
	free (fd);
}

void test_supprimer (){
	ArbreBinaireDeLettres a = ABDL_ajouterRacine ('a',TRUE,ABDL_arbreBinaireDeLettres(),ABDL_arbreBinaireDeLettres());
	ArbreBinaireDeLettres racine = ABDL_ajouterRacine ('b',FALSE,ABDL_arbreBinaireDeLettres(),a);
	ABDL_supprimer (&racine);
	CU_ASSERT_TRUE (racine == NULL);
	free (a);
	free (racine);
}


int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : Arbre binaire de lettre", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

/* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "obtenir la lettre", test_L_obtenirLaLettre))
      || (NULL == CU_add_test(pSuite, "obtenir si est fin de mot", test_L_obtenirEstFinDeMot))
      || (NULL == CU_add_test(pSuite, "fixer la lettre", test_L_fixerLaLettre))
      || (NULL == CU_add_test(pSuite, "fixer fin de mot", test_L_fixerFinDeMot))
      || (NULL == CU_add_test(pSuite, "arbre vide", test_ABDL_arbreBinaireDeLettres))
      || (NULL == CU_add_test(pSuite, "arbre est vide", test_ABDL_estVide))
      || (NULL == CU_add_test(pSuite, "obtenir la lettre + Booleen", test_ABDL_obtenirLettre))
      || (NULL == CU_add_test(pSuite, "fixer la lettre + Booleen", test_ABDL_fixerLettre))
      || (NULL == CU_add_test(pSuite, "obtenir fils gauche", test_ABDL_obtenirFilsGauche))
      || (NULL == CU_add_test(pSuite, "obtenir fils droit", test_ABDL_obtenirFilsDroit))
      || (NULL == CU_add_test(pSuite, "fixer fils gauche", test_ABDL_fixerFilsGauche))
      || (NULL == CU_add_test(pSuite, "fixer fils droit", test_ABDL_fixerFilsDroit))
      || (NULL == CU_add_test(pSuite, "ajouter racine", test_ABDL_ajouterRacine))
      || (NULL == CU_add_test(pSuite, "supprimer racine", test_ABDL_supprimerRacine))
      || (NULL == CU_add_test(pSuite, "supprimer", test_supprimer))
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
