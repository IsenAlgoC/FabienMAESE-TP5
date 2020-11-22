#include "tab.h"

int initTab(int* tab, int size) {


	if ((tab == NULL) || (size < 0)) {
		return -1;
	}

	for (int i = 0; i < size; i++) {
		tab[i] = 0;
	}

	return size;

}

int afficheTab(int* tab, int size, int nbElts) {

	
	if ((tab == NULL) || (size < nbElts) || (size < 0)) {
		return -1;
	}

	
	printf("\n");
	for (int i = 0; i < nbElts; i++) {
		printf("%d ", tab[i]);
		
	}

	return 0;
}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {


	if ((*size <= 0) || (tab == NULL) || (*nbElts <= 0)) {
		return NULL;
	}

	if (*nbElts < *size) {				// cas où le tableau est assez grand
		*(tab + *nbElts) = element;		/// on ajoute l'élément à la suite des valeurs
		(*nbElts)++;
	}

	else									//cas où le tableau n'est pas assez grand
	{
		int* temp = tab;				// on initialise une sauvegarde du tableau dans le cas d'un mauvais fonctionnement de realloc
		int nouvelle_taille = *size + TAILLEAJOUT;

		tab = (int*)realloc(tab, nouvelle_taille * sizeof(int));		// on effectue une réallocation de mémoire pour ajouter TAILLEAJOUT éléments
		*size = nouvelle_taille;

		if (tab == NULL) {			// si la réallocation n'a pas fonctionné
			tab = temp;
			return NULL;
		}


		tab[*nbElts] = element;		// on ajoute l'élément à la suite des valeurs
		*size = nouvelle_taille;
		(*nbElts)++;			
	}

	return tab;

}