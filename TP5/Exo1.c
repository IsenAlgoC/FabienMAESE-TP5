#include"tab.h"
#define TABSIZE 10
#define TAILLEINITIALE 100
#define TAILLEAJOUT 50

int main() {

	int MyTab1[TABSIZE];
	initTab(&MyTab1, TABSIZE);
	afficheTab(&MyTab1, TABSIZE, 7);
	// Déclaration du pointeur et des variables qui mémorisent la taille du tableau
	// et le nombre de valeurs qui y sont rangées :
	int* myTab2 = NULL;
	int tabSize = TAILLEINITIALE;
	int nbElts = 0;
	// Allocation de la mémoire :
	myTab2 = (int*)malloc(TAILLEINITIALE * sizeof(int));
	if (myTab2 != NULL) { initTab(myTab2, tabSize); }
	else { printf("mémoire insuffisante"); return(-1); }
}
