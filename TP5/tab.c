#include "tab.h"

int initTab(int* tab, int size) {
	

	if ((tab==NULL) || (size < 0)) {		
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
	
	for (int i = 0; i < nbElts; i++) {
		printf("%d ", tab[i]);
	}

	return 0;
}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (tab == NULL || size == NULL || nbElts == NULL) {
		return NULL;
	}
	if (*size <= *nbElts) {
		tab = (int*)realloc(tab, (*size + TAILLEAJOUT)* sizeof(int));
		if (tab== NULL){
			return NULL;
		}
		
	}

	tab[*nbElts] = element;
	*nbElts += 1;
	*size = *size + TAILLEAJOUT;
	return tab;



}