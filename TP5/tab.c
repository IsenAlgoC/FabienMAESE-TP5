#include "tab.h"
#define TABSIZE 10

int initTab(int* tab, int size) {
	

	if ((&tab==NULL) || (size < 0)) {		
		return -1;
	}
	
	for (int i = 0; i < size; i++) {
		tab[i] = 0;
	}

	return size;

}

int afficheTab(int* tab, int size, int nbElts) {

	if ((&tab == NULL) || (size < nbElts) || (size < 0)) {
		return -1;
	}
	
	for (int i = 0; i < nbElts; i++) {
		printf("%d ", tab[i]);
	}

	return 0;
}

