#include"tab.h"
#define TABSIZE 10
#define TAILLEINITIALE 100
#define TAILLEAJOUT 50

int main() {

	int MyTab1[TABSIZE];
	initTab(&MyTab1, TABSIZE);
	afficheTab(&MyTab1, TABSIZE, 7);
	// D�claration du pointeur et des variables qui m�morisent la taille du tableau
	// et le nombre de valeurs qui y sont rang�es :
	int* myTab2 = NULL;
	int tabSize = TAILLEINITIALE;
	int nbElts = 0;
	// Allocation de la m�moire :
	myTab2 = (int*)malloc(TAILLEINITIALE * sizeof(int));
	if (myTab2 != NULL) { initTab(myTab2, tabSize); }
	else { printf("m�moire insuffisante"); return(-1); }
}
