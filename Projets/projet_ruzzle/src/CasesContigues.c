#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>

#include "CasesContigues.h"
#include "Booleen.h"
#include "Case.h"
#include "Mot.h"


CasesContigues CC_casesContigues () {
  errno = 0;
  return NULL;
}

Booleen CC_estVide (CasesContigues desCasesContigues) {
  errno = 0;
  return (desCasesContigues == NULL);
}

Case CC_obtenirCase(CasesContigues desCasesContigues){
  assert(!(CC_estVide (desCasesContigues)));
  errno = 0;
  return desCasesContigues -> uneCase;
}

CasesContigues CC_obtenirCasesSuivantes (CasesContigues desCasesContigues){
  assert(!(CC_estVide (desCasesContigues)));
  errno = 0;
  return desCasesContigues -> casesSuivantes;
}

void CC_fixerCasesContiguesSuivante( CasesContigues* desCasesContigues, CasesContigues casesContiguesAFixer){
  assert(!(CC_estVide (*desCasesContigues)));
  errno = 0;
  (*desCasesContigues) -> casesSuivantes = casesContiguesAFixer;
}

Booleen CC_estPresent (CasesContigues desCasesContigues, Case uneCase){
  // fonction recursive
  if (CC_estVide (desCasesContigues)) {
    return FALSE;
  } else {
    if (C_sontEgales (CC_obtenirCase (desCasesContigues), uneCase)) {
      return TRUE;
    } else {
      return CC_estPresent (CC_obtenirCasesSuivantes (desCasesContigues), uneCase);
    }
  }
}

void CC_ajouterCase (CasesContigues* desCasesContigues, Case uneCase){
  assert(!(C_estDejaUtilisee (uneCase)));
  CasesContigues pNoeud=(CasesContigues) malloc (sizeof(Noeud));
  if (pNoeud!=NULL){
    errno=0;
    pNoeud -> uneCase = uneCase;
    pNoeud -> casesSuivantes = *desCasesContigues;
    *desCasesContigues=pNoeud;
  } else {
    errno=1;
  }
}

unsigned int CC_longueur (CasesContigues desCasesContigues){
  // fonction récursive
  if (CC_estVide (desCasesContigues)){
    return 0;
  } else {
    return 1 + CC_longueur (CC_obtenirCasesSuivantes (desCasesContigues));
  }
}

unsigned int CC_scoreCasesContiguesSansBonusMot (CasesContigues desCasesContigues){
  // fonction recursive on additionne le nb de point multiplié par le bonnus Lettre de chacune des cases
  if ((CC_estVide(desCasesContigues))){
    return 0;
  } else {
    return(C_obtenirNbPoints (CC_obtenirCase (desCasesContigues)) * C_bonusLettreEnNaturel (CC_obtenirCase (desCasesContigues))) + CC_scoreCasesContiguesSansBonusMot(CC_obtenirCasesSuivantes(desCasesContigues));
  }
}


unsigned int CC_scoreCasesContigues (CasesContigues desCasesContigues){
  int multiplicateur = 1 ;
  CasesContigues copie = desCasesContigues;
  // on travaille avec une copie pour pouvoir utiliser par la suite CC_scoreCasesContiguesSansBonusMot sur desCasesContigues
  while (!(CC_estVide (copie))){
    multiplicateur = C_bonusMotEnNaturel (CC_obtenirCase (copie)) * multiplicateur;
    copie = CC_obtenirCasesSuivantes(copie);
  }
  return (multiplicateur * CC_scoreCasesContiguesSansBonusMot (desCasesContigues));
}

Mot CC_casesContiguesEnMotRec (CasesContigues desCasesContigues){
  // fonction récursive privee
  if (CC_estVide (CC_obtenirCasesSuivantes (CC_obtenirCasesSuivantes (desCasesContigues)))){
    return M_mot (CC_obtenirCase (CC_obtenirCasesSuivantes (desCasesContigues)).lettre,(CC_obtenirCase (desCasesContigues).lettre));
  } else {
    return M_allongerMot (CC_casesContiguesEnMot (CC_obtenirCasesSuivantes (desCasesContigues)),CC_obtenirCase (desCasesContigues).lettre);
  }
}

Mot CC_casesContiguesEnMot (CasesContigues desCasesContigues){
    return CC_casesContiguesEnMotRec (desCasesContigues);
}

void CC_supprimerTeteCase (CasesContigues* desCasesContigues){
  assert(!(CC_estVide (*desCasesContigues)));
  CasesContigues temp = *desCasesContigues;
  *desCasesContigues = CC_obtenirCasesSuivantes (*desCasesContigues);
  free (temp);
}

void CC_supprimer (CasesContigues *desCasesContigues){
  errno = 0;
  if (!CC_estVide (*desCasesContigues)){
    CC_supprimerTeteCase (desCasesContigues);
    CC_supprimer (desCasesContigues);
  }
}
