#pragma once

#include <stdio.h>
#include <stdlib.h>
#define TAILLEINITIALE 100

typedef struct Tableau {

	int* elt; // le tableau d’entiers
	int size; // la taille de ce tableau d’entiers
	int eltsCount; // le nombre d’éléments dans le tableau

} TABLEAU;


TABLEAU newArray();
//^crée un nouveau TABLEAU en allouant une taille initiale pour les données.