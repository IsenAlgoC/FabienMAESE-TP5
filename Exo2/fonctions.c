#include "tab2.h"

int initTab(TABLEAU tab) {


	if ((tab.elt == NULL) || (tab.size < 0)) {		//on va r�utiliser la fonction initTab de l'exo 1 que l'on modifie un peu avec la structure TABLEAU
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


	if (TAB.elt != NULL) {			//si l'allocation a r�ussi, elt pointe vers le tableau, qu'on initialise alors � z�ro en utilisant la fonction de l'ex1.
		initTab(TAB);
	}

	return TAB;

}

int incrementArraySize(TABLEAU* tab, int incrementValue) {

	int* temp = tab->elt;

	if ((tab->size <= 0) || (tab->elt == NULL) || (tab->eltsCount <= 0)) {
		return -1;
	}

	tab->elt = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));		//r�allocation de la m�moire
	
	if (tab->elt == NULL) {			// si la r�allocation n'a pas fonctionn�
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

		if (tab->elt == NULL) {			// si la r�allocation n'a pas fonctionn�
			tab->elt = temp;
			return 0;
		}
	}

	tab->elt[pos - 1] = element;    // la premi�re valeur, elt[0], est en positon 1, donc la valeur en position pos sera elt[pos-1]

	return pos;

}


int displayElements(TABLEAU* tab, int startPos, int endPos) {

	if ((tab->elt == NULL) || (tab->size < tab->eltsCount) || (tab->size < 0)) {
		return -1;
	}


	printf("\n");	// pour un peu de clart�

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
		// si startPos <= endPos, on supprime tous les �l�ments entre ces bornes pour les remplacer par les �l�ments qui se situent apr�s endPos
		for (int i = endPos; i < tab->size; i++) {		
			tab->elt[startPos + j] = tab->elt[endPos + j];
			j += 1;
		}
	}

	else {
		int j = 0;
		// si endPos <= startPos, on commence � enlever des �l�ments � la fin du tableau. Arriv� � la fin, on repart � 0 pour continuer � enlever
		// jusque endPos. Il faut donc supprimer tous les �l�ments apr�s startPos, et d�caler de endPos toutes les valeurs apr�s endPos

		for (int i = startPos; i < tab->size; i++) {		// r�initialisation des valeurs � partir de startPos jusqu'� la fin du tableau
			tab->elt[i] = 0;
		}

		tab->size = startPos - endPos -1;  //formule trouv�e apr�s un peu de r�flexion sur papier pour la nouvelle taille du tableau

		int k = 0;
		for (int i = endPos + 1; i < startPos; i++) {
			tab->elt[k] = tab->elt[i];
			tab->elt[i] = 0;
			k += 1;

		}
	}
	int TailleAEnlever = -((TailleInitiale - startPos) + endPos + 1);
	incrementArraySize(tab, TailleAEnlever);	//r�allocation (r�duction) de la m�moire

	return(tab->size);

}