#pragma once

#include <stdio.h>
#include <stdlib.h>
#define TAILLEINITIALE 100

typedef struct Tableau {

	int* elt; // le tableau d�entiers
	int size; // la taille de ce tableau d�entiers
	int eltsCount; // le nombre d��l�ments dans le tableau

} TABLEAU;


TABLEAU newArray();
//^cr�e un nouveau TABLEAU en allouant une taille initiale pour les donn�es.