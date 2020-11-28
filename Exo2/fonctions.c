#include "tab2.h"

int initTab(TABLEAU tab) {


	if ((tab.elt == NULL) || (tab.size < 0)) {		//on va réutiliser la fonction initTab de l'exo 1 que l'on modifie un peu avec la structure TABLEAU
		return -1;
	}

	for (int i = 0; i < tab.size; i++) {
		tab.elt[i] = 0;
	}

	return tab.size;

}


TABLEAU newArray() {

	TABLEAU TAB;
	TAB.size = TAILLEINITIALE;
	TAB.eltsCount = 0;
	TAB.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));


	if (TAB.elt != NULL) {			//si l'allocation a réussi, elt pointe vers le tableau, qu'on initialise alors à zéro en utilisant la fonction de l'ex1.
		initTab(TAB);
	}

	return TAB;

}

int incrementArraySize(TABLEAU* tab, int incrementValue) {

	int* temp = tab->elt;

	if ((tab->size <= 0) || (tab->elt == NULL) || (tab->eltsCount <= 0)) {
		return -1;
	}

	tab->elt = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));		//réallocation de la mémoire
	
	if (tab->elt == NULL) {			// si la réallocation n'a pas fonctionné
		tab->elt = temp;
		return -1;
	}

	tab->size = tab->size + incrementValue;

	return tab->size;

}

int setElement(TABLEAU* tab, int pos, int element) {

	int* temp = tab->elt;

	if (pos > tab->size) {
		incrementArraySize(tab, pos);

		if (tab->elt == NULL) {			// si la réallocation n'a pas fonctionné
			tab->elt = temp;
			return 0;
		}
	}

	tab->elt[pos - 1] = element;    // la première valeur, elt[0], est en positon 1, donc la valeur en position pos sera elt[pos-1]

	return pos;

}


int displayElements(TABLEAU* tab, int startPos, int endPos) {

	if ((tab->elt == NULL) || (tab->size < tab->eltsCount) || (tab->size < 0)) {
		return -1;
	}


	printf("\n");	// pour un peu de clarté

	if (startPos <= endPos) {
		for (int i = startPos; i < endPos; i++) {
			printf("%d ", tab->elt[i]);

		}
	}
	else {
		for (int i = startPos; i < tab->eltsCount; i++) {
			printf("%d ", tab->elt[i]);
		}

		for (int i = 0; i <= endPos; i++) {
			printf("%d ", tab->elt[i]);
		}
	}
	

	return 0;


}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {

	int TailleInitiale = tab->size;

	if ((tab->elt == NULL) || (tab->size < tab->eltsCount) || (tab->size < 0)) {		//teste les erreurs, encore une fois
		return -1;
	}

	if (startPos <= endPos) {
		int j = 0;
		// si startPos <= endPos, on supprime tous les éléments entre ces bornes pour les remplacer par les éléments qui se situent après endPos
		for (int i = endPos; i < tab->size; i++) {		
			tab->elt[startPos + j] = tab->elt[endPos + j];
			j += 1;
		}
	}

	else {
		int j = 0;
		// si endPos <= startPos, on commence à enlever des éléments à la fin du tableau. Arrivé à la fin, on repart à 0 pour continuer à enlever
		// jusque endPos. Il faut donc supprimer tous les éléments après startPos, et décaler de endPos toutes les valeurs après endPos

		for (int i = startPos; i < tab->size; i++) {		// réinitialisation des valeurs à partir de startPos jusqu'à la fin du tableau
			tab->elt[i] = 0;
		}

		tab->size = startPos - endPos -1;  //formule trouvée après un peu de réflexion sur papier pour la nouvelle taille du tableau

		int k = 0;
		for (int i = endPos + 1; i < startPos; i++) {
			tab->elt[k] = tab->elt[i];
			tab->elt[i] = 0;
			k += 1;

		}
	}
	int TailleAEnlever = -((TailleInitiale - startPos) + endPos + 1);
	incrementArraySize(tab, TailleAEnlever);	//réallocation (réduction) de la mémoire

	return(tab->size);

}