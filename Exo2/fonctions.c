#include "deuxtab.h"

int initTab(int* tab, int size) {


	if ((tab == NULL) || (size < 0)) {		//on va réutiliser la fonction initTab de l'exo 1
		return -1;
	}

	for (int i = 0; i < size; i++) {
		tab[i] = 0;
	}

	return size;

}



TABLEAU newArray() {

	TABLEAU TAB;
	TAB.size = TAILLEINITIALE;
	TAB.eltsCount = 0;
	int* elt;
	elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
	TAB.elt = elt;



	if (elt != NULL) {			//si l'allocation a réussi, elt pointe vers le tableau, qu'on initialise alors à zéro en utilisant la fonction de l'ex1.
		initTab(elt, TAILLEINITIALE);
	}

	return TAB;

}