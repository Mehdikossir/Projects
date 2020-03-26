#include <stdlib.h>
#include <CUnit/Basic.h>
#include "ListeOrdonnee.h"

int init_suite_success (void){
  return 0;
}

int clean_suite_success (void){
  return 0;
}
void test_R_obtenirScore (void){
  Resultat res;
  res.mot = "abcd";
  res.score = 4;
  CU_ASSERT_TRUE (R_obtenirScore(res) == res.score);
}

void test_R_obtenirMot (void){
  Resultat res;
  res.mot = "abcd";
  res.score = 4;
  CU_ASSERT_TRUE (R_obtenirMot(res) == res.mot);
}


void test_L_listeChainee (void){
  CU_ASSERT_TRUE (L_listeChainee () == NULL);
}

void test_L_estVide (void){
  ListeChainee l = L_listeChainee ();
  CU_ASSERT_TRUE (l == NULL);
}

void test_L_ajouterEnTete (void){
  Resultat res;
  res.mot = "abcd";
  res.score = 4;
  ListeChainee pNoeud = L_listeChainee ();
  L_ajouterEnTete (&pNoeud, res);
  CU_ASSERT_TRUE (L_obtenirResultat(pNoeud).score == res.score);
}

void test_L_obtenirResultat (void){
  Resultat res;
  res.mot = "abcd";
  res.score = 4;
  ListeChainee pNoeud = (ListeChainee) malloc (sizeof(L_Noeud));
  pNoeud -> Resultat = res;
  CU_ASSERT_TRUE (L_obtenirResultat(pNoeud).score == res.score);
}

void test_L_obtenirListeSuivante (void){
  ListeChainee pNoeud = (ListeChainee) malloc (sizeof(L_Noeud));
  pNoeud -> listeSuivante = L_listeChainee ();
  CU_ASSERT_TRUE (L_obtenirListeSuivante (pNoeud) == NULL);
}


void test_L_fixerElement (void){
  Resultat res;
  res.mot = "abcd";
  res.score = 4;
  ListeChainee pNoeud = (ListeChainee) malloc (sizeof(L_Noeud));
  L_fixerElement (&pNoeud,res);
  CU_ASSERT_TRUE (L_obtenirResultat(pNoeud).score == res.score);
}

void test_L_fixerListeSuivante (void){
  ListeChainee l = L_listeChainee();
  ListeChainee pNoeud = (ListeChainee) malloc (sizeof(L_Noeud));
  L_fixerListeSuivante (&pNoeud,l);
  CU_ASSERT_TRUE (L_obtenirListeSuivante(pNoeud) == NULL);
}

void test_L_supprimerTete (void){
  Resultat res;
  res.mot = "abcd";
  res.score = 4;
  ListeChainee pNoeud = (ListeChainee) malloc (sizeof(L_Noeud));
  pNoeud -> Resultat = res;
  pNoeud -> listeSuivante = L_listeChainee();
  L_supprimerTete (&pNoeud);
  CU_ASSERT_TRUE (L_estVide (pNoeud));
}
void test_L_supprimer (void){
  Resultat res;
  res.mot = "abcd";
  res.score = 4;
  ListeChainee pNoeud = (ListeChainee) malloc (sizeof(L_Noeud));
  pNoeud -> Resultat = res;
  pNoeud -> listeSuivante = L_listeChainee ();
  L_supprimer (&pNoeud);
  CU_ASSERT_TRUE (L_estVide (pNoeud));
}

void test_L_insertion_listeVide (void){
  CasesContigues casesContigues;Case case1, case2, case3, case4; ListeChainee liste;
  case1 = C_initialisationCase ('e',2,'V'+'D',FALSE);
  case2 = C_initialisationCase ('l',4,'V'+'D',FALSE);
  case3 = C_initialisationCase ('l',4,'V'+'D',FALSE);
  case4 = C_initialisationCase ('e',2,'V'+'D',FALSE);
  casesContigues =  CC_casesContigues ();
  CC_ajouterCase (&casesContigues, case1);
  CC_ajouterCase (&casesContigues, case2);
  CC_ajouterCase (&casesContigues, case3);
  CC_ajouterCase (&casesContigues, case4);
  liste = L_listeChainee ();
  L_insertion (&liste, casesContigues);
  CU_ASSERT_TRUE (M_sontEgaux (L_obtenirResultat (liste).mot, CC_casesContiguesEnMot(casesContigues)));
}

void test_L_insertion (void){
  CasesContigues casesContigues1, casesContigues2; Case case1, case2, case3, case4; ListeChainee liste;
  case1 = C_initialisationCase ('e',2,'V'+'D',FALSE);
  case2 = C_initialisationCase ('l',4,'V'+'D',FALSE);
  case3 = C_initialisationCase ('l',4,'V'+'D',FALSE);
  case4 = C_initialisationCase ('e',2,'V'+'D',FALSE);
  casesContigues1 =  CC_casesContigues ();
  CC_ajouterCase (&casesContigues1, case1);
  CC_ajouterCase (&casesContigues1, case2);
  CC_ajouterCase (&casesContigues1, case3);
  CC_ajouterCase (&casesContigues1, case4);
  case1 = C_initialisationCase ('i',3,'V'+'D',FALSE);
  case2 = C_initialisationCase ('l',2,'V'+'D',FALSE);
  casesContigues2 =  CC_casesContigues ();
  CC_ajouterCase (&casesContigues2, case1);
  CC_ajouterCase (&casesContigues2, case2);
  liste = L_listeChainee ();
  L_insertion (&liste,casesContigues1);
  L_insertion (&liste,casesContigues2);
  CU_ASSERT_TRUE (M_sontEgaux (L_obtenirResultat (liste).mot, CC_casesContiguesEnMot (casesContigues1)));
}

void test_L_estPresent (void){
  Resultat res; CasesContigues casesContigues1; ListeChainee liste; Case case1, case2;
  res.mot = "ab";
  res.score = 4;
  case1 = C_initialisationCase ('a',2,'V'+'D',FALSE);
  case2 = C_initialisationCase ('b',2,'V'+'D',FALSE);
  casesContigues1 =  CC_casesContigues ();
  CC_ajouterCase (&casesContigues1, case1);
  CC_ajouterCase (&casesContigues1, case2);
  liste = L_listeChainee ();
  L_insertion (&liste,casesContigues1);
  CU_ASSERT_TRUE (L_estPresent (&liste, R_obtenirMot(res)));
}

int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : Liste ordonnée", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

/* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "test obtenir score", test_R_obtenirScore))
    || (NULL == CU_add_test(pSuite, "test obtenir mot", test_R_obtenirMot))
    || (NULL == CU_add_test(pSuite, "test liste chainee", test_L_listeChainee))
    || (NULL == CU_add_test(pSuite, "test est vide liste chainee", test_L_estVide))
    || (NULL == CU_add_test(pSuite, "test ajout en tete d'une liste chainee", test_L_ajouterEnTete))
    || (NULL == CU_add_test(pSuite, "test obtenirResultat ", test_L_obtenirResultat))
    || (NULL == CU_add_test(pSuite, "test obtenir liste suivante d'ue liste chainee", test_L_obtenirListeSuivante))
    || (NULL == CU_add_test(pSuite, "test fixer element", test_L_fixerElement))
    || (NULL == CU_add_test(pSuite, "test fixer liste suivante", test_L_fixerListeSuivante))
    || (NULL == CU_add_test(pSuite, "test supprimer tete", test_L_supprimerTete))
    || (NULL == CU_add_test(pSuite, "test supprimer", test_L_supprimer))
    || (NULL == CU_add_test(pSuite, "test insertion dans une  liste vide", test_L_insertion_listeVide))
    || (NULL == CU_add_test(pSuite, "test insertion", test_L_insertion))
    || (NULL == CU_add_test(pSuite, "test est present", test_L_estPresent))
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
