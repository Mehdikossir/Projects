#ifndef __SERIALISER_DICO__
#define __SERIALISER_DICO__

#include "Dictionnaire.h"
#include <stdlib.h>
#include <stdio.h>

/** creerDictionnaire retourne un Dictionnaire à partir du fichier texte en entrée contenant des mots*/
Dictionnaire creerDictionnaire (FILE* fic); 
/** serialiserDictionnaire créé un fichier permettant de stocker efficacement un dictionnaire de manière recursive*/
void serialiserDictionnaire (FILE* fic, Dictionnaire unDico);

#endif
