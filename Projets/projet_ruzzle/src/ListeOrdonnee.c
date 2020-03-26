#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include "ListeOrdonnee.h"

unsigned int R_obtenirScore (Resultat resultat){
  return resultat.score;
}

Mot R_obtenirMot (Resultat resultat){
  return resultat.mot;
}

ListeChainee L_listeChainee (){
  errno = 0;
  return NULL;
}

Booleen L_estVide (ListeChainee l){
  errno=0;
  return (l == NULL);
}

void L_ajouterEnTete (ListeChainee* pl, Resultat resultat){
  ListeChainee pNoeud = (ListeChainee) malloc (sizeof(L_Noeud));
  if (pNoeud!=NULL){
    errno=0;
    pNoeud -> Resultat = resultat;
    pNoeud -> listeSuivante = *pl;
    *pl=pNoeud;
  } else {
  errno=1;
  }
}

Resultat L_obtenirResultat (ListeChainee l){
  assert (!L_estVide (l));
  errno=0;
  return l -> Resultat;
}

ListeChainee L_obtenirListeSuivante (ListeChainee l){
  assert (!L_estVide (l));
  errno=0;
  return l -> listeSuivante;
}

void L_fixerElement (ListeChainee* pl, Resultat resultat){
  assert (!L_estVide (*pl));
  errno=0;
  (*pl) -> Resultat = resultat;
}

void L_fixerListeSuivante (ListeChainee* pl, ListeChainee suivant){
  assert (!L_estVide (*pl));
  errno=0;
  (*pl) -> listeSuivante = suivant;
}

void L_afficher (ListeChainee l){
  assert (!L_estVide (l));
  unsigned int compteur = 0;
  Resultat resultat;
  errno=0;
  while(!L_estVide(l)){
    resultat = L_obtenirResultat (l);
    printf("%d :",R_obtenirScore (resultat));
    M_afficherMot (R_obtenirMot (resultat));
    printf("\n");
    l = L_obtenirListeSuivante (l);
    compteur = compteur + 1;
  }
  printf("Il y a %d mots dans la grille de Ruzzle\n", compteur );
}

void L_supprimerTete (ListeChainee* pl){
  ListeChainee temp;
  assert (!L_estVide (*pl));
  errno=0;
  temp=*pl;
  *pl = L_obtenirListeSuivante (*pl);
  free (temp);
}

void L_supprimer (ListeChainee* pl){
  errno=0;
  if (!L_estVide (*pl)) {
    L_supprimerTete (pl);
    L_supprimer (pl);
  }
}

void L_insertion (ListeChainee* liste, CasesContigues casesContigues){
  errno=0;
  ListeChainee temp; Resultat resultat;
  resultat.mot = CC_casesContiguesEnMot (casesContigues);
  resultat.score = CC_scoreCasesContigues (casesContigues);

  if (L_estVide (*liste)){
    L_ajouterEnTete (liste,resultat);
  } else {
     if (!L_estPresent (liste,R_obtenirMot (resultat))){
          if (R_obtenirScore (L_obtenirResultat (*liste)) < R_obtenirScore (resultat))
              L_ajouterEnTete (liste,resultat);
          else {
              temp = L_obtenirListeSuivante(*liste);
              L_insertion(&temp,casesContigues);
              L_fixerListeSuivante(liste,temp);
            }
     }
  }
}

Booleen L_estPresent (ListeChainee* Liste, Mot mot){
  ListeChainee temp;
  if (L_estVide (*Liste)){
      return FALSE;
  } else {
      if(M_sontEgaux (R_obtenirMot (L_obtenirResultat (*Liste)),mot)){
        return TRUE;
      } else {
        temp = L_obtenirListeSuivante (*Liste);
        return L_estPresent (&temp,mot);
      }
  }
}
