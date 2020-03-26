#ifndef _Mot_
#define _Mot_

#include <string.h>
#include <ctype.h>

/** Un Mot est définie comme une chaine de caractère,sans caractère spécial .*/
typedef char* Mot;

/** Un Mot est créer a partir de deux lettres*/
Mot M_mot (char lettre1,char lettre2);
/** M_sontEgaux permet de savoir si deux mots sont égales.*/
int M_sontEgaux(Mot mot1,Mot mot2);
/** M_estUnMot permet de savoir si une chaine de caractère est un mot.*/
int M_estUnMot (char* chaine);
/** M_allongerMot permet d'ajouter une lettre a un mot.*/
Mot M_allongerMot (Mot mot , char lettre);
/** M_chaineEnMot permet de transformer une chaine de caractere en mot*/
Mot M_chaineEnMot (char* chaine);
/** M_longeurMot permet d'obtenir la longeur d'un mot*/
size_t M_longeurMot (Mot mot );
/** M_iemeLettre permet d'obtenir la ieme lettre d'un mot*/
char M_iemeLettre (Mot mot,unsigned int position );
/** M_estEnOrdreAlphabetique permet de savoir si deux mots sont en ordre alphabétique*/
int M_estEnOrdreAlphabetique (Mot mot1,Mot mot2 );
/** M_estCaractereSpecial permet de savoir si un caractere est un caractère spècial*/
int M_estCaractereSpecial (char caractere);
/** M_afficherMot permet d'afficher un mot*/
void M_afficherMot (Mot mot);
/** M_transformerMotMajenMin permet de transformer un mot en majuscule en miniscule*/
Mot M_transformerMotMajenMin (Mot mot);

#endif
