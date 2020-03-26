#include <stdlib.h>
#include <stdio.h>
#include "Case.h"
#include "Booleen.h"

Case C_initialisationCase(char lettre, unsigned int nbPoints, Bonus bonus,Booleen dejaUtilisee){
  Case uneCase;
  uneCase.lettre = lettre;
  uneCase.nbPoints = nbPoints;
  uneCase.bonus = bonus;
  uneCase.dejaUtilisee = dejaUtilisee;
  return uneCase;
}

unsigned int C_obtenirNbPoints (Case uneCase) {
    return uneCase.nbPoints;
}

char C_obtenirLettre (Case uneCase){
    return uneCase.lettre;
}

Bonus C_obtenirBonus (Case uneCase){
    return uneCase.bonus;
}

Booleen C_estDejaUtilisee (Case uneCase){
    return uneCase.dejaUtilisee;
}

Booleen C_sontEgales(Case uneCase1, Case uneCase2){
    if ((uneCase1.lettre == uneCase2.lettre) && (uneCase1.nbPoints == uneCase2.nbPoints)
    && (uneCase1.bonus == uneCase2.bonus) && (uneCase1.dejaUtilisee == uneCase2.dejaUtilisee)){
      return TRUE;
    }
      return FALSE;
}

unsigned int C_bonusLettreEnNaturel (Case uneCase){
  if (uneCase.bonus == 'L' + 'D'){
    return 2;
  } else if (uneCase.bonus == 'L' + 'T'){
    return 3;
  } else {
    return 1;
  }
}

unsigned int C_bonusMotEnNaturel (Case uneCase){
  if (uneCase.bonus == 'M'+'D'){
    return 2;
  } else if (uneCase.bonus == 'M'+'T'){
  return 3;
  } else {
  return 1;
  }
}
