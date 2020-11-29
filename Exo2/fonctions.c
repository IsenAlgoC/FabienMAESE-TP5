#include "tab2.h"

int initTab(TABLEAU tab, int startPos, int endPos) {


	if ((tab.elt == NULL) || (tab.size < 0)) {		//on va r�utiliser la fonction initTab de l'exo 1 que l'on modifie un peu avec la structure TABLEAU
		return -1;
	}

	for (int i = startPos; i < endPos; i++) {
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
		initTab(TAB, 0, TAILLEINITIALE);
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

	initTab(*tab, tab->size, tab->size + incrementValue);
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

	tab->elt[pos ] = element;    
	tab->eltsCount += 1;
	return pos;

}


int displayElements(TABLEAU* tab, int startPos, int endPos) {

	if ((tab->elt == NULL) || (tab->size < tab->eltsCount) || (tab->size < 0)) {
		return -1;
	}


	printf("\n");	// pour un peu de clart�

	if (startPos <= endPos) {
		for (int i = startPos; i <= endPos; i++) {
			printf("%d ", tab->elt[i]);

		}
	}
	else {
		for (int i = startPos; i < tab->size; i++) {
			printf("%d ", tab->elt[i]);
		}

		for (int i = 0; i <= endPos; i++) {
			printf("%d ", tab->elt[i]);
		}
	}
	

	return 0;


}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {

	int TailleInitiale = tab->size;	// on prend en m�moire la taille du tableau � l'initialisation, car on va la modifier plus tard

	if ((tab->elt == NULL) || (tab->size < tab->eltsCount) || (tab->size < 0) || (endPos >= tab->size)) {		//teste les erreurs, encore une fois
		return -1;
	}

	if (startPos <= endPos) {
	
		// si startPos <= endPos, on supprime tous les �l�ments entre ces bornes pour les remplacer par les �l�ments qui se situent apr�s endPos
		for (int i = 0; i + endPos< TailleInitiale; i++) {		
			tab->elt[i+startPos] = tab->elt[endPos +1+ i];
			
		}
		tab->eltsCount = startPos + (tab->size - endPos - 1);
		tab->size = tab->size - (endPos - startPos +1);
		
	}

	else {
		
		// si endPos <= startPos, on commence � enlever des �l�ments � la fin du tableau. Arriv� � la fin, on repart � 0 pour continuer � enlever
		// jusque endPos. Il faut donc supprimer tous les �l�ments apr�s startPos, et d�caler de endPos toutes les valeurs apr�s endPos

		for (int i = startPos; i < TailleInitiale; i++) {		// r�initialisation des valeurs � partir de startPos jusqu'� la fin du tableau
			tab->elt[i] = 0;		
			tab->eltsCount -= 1;
		}

		//tab->size = startPos - endPos -1;  //formule trouv�e apr�s un peu de r�flexion sur papier pour la nouvelle taille du tableau

		int k = 0;
		for (int i = endPos ; i < startPos; i++) {
			tab->elt[k] = tab->elt[i];
			k += 1;
			tab->eltsCount -= 1;
		}

		for (int i = startPos; i < tab->size; i++) {
			tab->elt[i] = 0;
		}
		tab->eltsCount -= 1; // parce que le compte est trop grand de 1; 
		tab->size = startPos - endPos - 1;
	
	}


	tab->elt = (int*)realloc(tab->elt, (tab->size) * sizeof(int));		//r�duction de la m�moire	

	//la console indique un seul warning que je n'arrive pas � �viter et qui est li� � la r�alloc. 
	//Cependant, l'�ventualit� que r�alloc retourne un pointeur NULL est trait�e juste en dessous
	

	if (tab->elt == NULL) {			// si la r�duction n'a pas fonctionn�
		return -1;
	}


	return(tab->size);

}