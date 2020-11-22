#include"tab.h"

void main() {

	int MyTab1[10];			// création du tableau statique MyTab1 
	// Déclaration du pointeur et des variables qui mémorisent la taille du tableau
	// et le nombre de valeurs qui y sont rangées :
	int* MyTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 0;
	
	// Allocation de la mémoire :

	MyTab2 = (int*)malloc(tabSize * sizeof(int));

	if (MyTab2 != NULL) {			//si l'allocation a réussi, MyTab2 pointe vers le tableau, qu'on initialise alors
		initTab(MyTab2, tabSize);
	}
	else {			//en cas de problème d'allocation
		printf("mémoire insuffisante");
		return(-1);
	}

	// remplacement des valeurs du tableau de 1 à 20

	for (int i = 0; i < 20; i++) {
		MyTab2[i] = i+1 ;
		nbElts++;
	}
	
	// affichage  du tableau
	afficheTab(MyTab2, TAB2SIZE, nbElts); // pas nécessaire puisqu'on l'affichera une deuxième fois plus tard

	// agrandissement du tableau pour qu'il fasse 400 valeurs. Ce nombre est modifiable autant que l'on veut

	for (int i= nbElts; i <= 400; i++) {
		ajoutElementDansTableau(MyTab2, &tabSize, &nbElts, i);
		
	}

	afficheTab(MyTab2, tabSize, nbElts);
	
	free(MyTab2);		// destruction du tableau pour ne pas consommer trop de mémoire
	
	
}
