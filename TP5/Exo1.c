#include"tab.h"

void main() {

	int MyTab1[10];
	// D�claration du pointeur et des variables qui m�morisent la taille du tableau
	// et le nombre de valeurs qui y sont rang�es :
	int* MyTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 20;

	// Allocation de la m�moire :

	MyTab2 = (int*)malloc(TAB2SIZE * sizeof(int));

	if (MyTab2 != NULL) { 
		initTab(MyTab2, tabSize); }

	else { printf("m�moire insuffisante"); return(-1); }
	
	// remplacement des valeurs du tableau de 1 � 20
	
	for (int i = 0; i < nbElts; i++) {
		MyTab2[i] = i+1;
		
	}

	// affichage  du tableau
	afficheTab(MyTab2, TAB2SIZE, nbElts);
	
	//test de la fonction ajoutElementDansTableau : 
	int lataille = TAB2SIZE;
	
	for (int i = nbElts+1; i < TAB2SIZE + TAILLEAJOUT; i++) {
		MyTab2 = ajoutElementDansTableau(MyTab2, &lataille, &nbElts, i);
	}
	
	afficheTab(MyTab2, TAB2SIZE, nbElts);
	
	


}
