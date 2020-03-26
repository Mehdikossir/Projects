#include <stdlib.h>
#include <stdio.h>
#include<assert.h>
#include "Mot.h"

#define True 1
#define False 0

int M_estCaractereSpecial(char caractere){
  if((caractere >='A' && caractere <= 'Z') || (caractere >= 'a' && caractere <= 'z')|| (caractere == '-' )){
    return False;
  } else {
    return True;
  }
}

Mot M_mot (char lettre1, char lettre2){
  assert(!M_estCaractereSpecial (lettre1));
  assert(!M_estCaractereSpecial (lettre2));
   Mot mot = malloc (3*sizeof(char));
   mot[0] = lettre1;
   mot[1] = lettre2;
   mot[2] = '\0';
 return mot;
 free (mot);
}

int M_sontEgaux (Mot mot1, Mot mot2){
  if(strcmp(mot1,mot2)==0){
    return True;
  }
  return False;
}

int M_estUnMot (char chaine[]){
  int i=0;
  while (i < strlen (chaine)){
    if(M_estCaractereSpecial (chaine[i]) == 1){
      return False;
    } else {
      i++;
    }
  }
    return True;
}


Mot M_allongerMot (Mot mot , char lettre){
  Mot nouveau_Mot;
    size_t t = strlen(mot);
    nouveau_Mot = malloc ((t+1) * sizeof(char));
    for(int i = 0; i < t; i++){
      nouveau_Mot[i] = mot[i];
    }
    nouveau_Mot[t] = lettre;
    nouveau_Mot[t+1] = '\0';
    return nouveau_Mot;
    free (nouveau_Mot);
}

Mot M_chaineEnMot (char* chaine){
  assert (M_estUnMot (chaine));
  return chaine;
}

size_t M_longeurMot (Mot mot ){
  return strlen (mot);
}

char M_iemeLettre (Mot mot, unsigned int position){
     assert(position <= M_longeurMot (mot));
     return mot[position];
}

int M_estEnOrdreAlphabetique (Mot mot1, Mot mot2 ){
  int min;
  int i = 1;
  if(M_longeurMot (mot1) >= M_longeurMot (mot2)){
    min = M_longeurMot (mot1);
  } else {
    min = M_longeurMot (mot2);
  }
  while ((mot1[i] == mot2[i]) && (i < min)){
    i++;
  }
  if(i >= min){
    return True;
  }
  if(mot1[i] < mot2[i]){
    return True;
  } else {
    return False;
  }
}

void M_afficherMot (Mot mot){
  unsigned int i;
  for(i=0; i < M_longeurMot (mot); i++){
    printf("%c",mot[i]);
  }
    printf("\n");
}

Mot M_transformerMotMajenMin (Mot mot){
  Mot nouveau_mot;
  size_t t = strlen(mot);
  nouveau_mot = malloc((t) * sizeof(char));
  for(int i=0; i<t; i++){
    nouveau_mot[i] = tolower(mot[i]);
    }
 nouveau_mot[t] = '\0';
 return nouveau_mot;
 free (nouveau_mot);
}
