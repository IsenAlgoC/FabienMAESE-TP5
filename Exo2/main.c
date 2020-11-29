#include "tab2.h"

int main() {

	// dans ces tests, on a baissé TAILLEINITIALE à 40 pour plus de clarté dans la console

	TABLEAU TAB=newArray();

	//displayElements(&TAB, 0, TAILLEINITIALE);				// newArray a bien fonctionné

	for (int i = 0; i < TAB.size; i++) {
		setElement(&TAB, i, i+1);						// remplit le tableau de 1 à (TAB.size -1)
	}
		
	displayElements(&TAB, 0, TAB.size-1);		//dans la fonction display, on affiche les valeurs dans [startPos; endPos], or TAB->elt[TAB.size] n'existe pas
	//displayElements(&TAB, TAILLEINITIALE, 20);				// la fonction displayElement fonctionne bien dans les deux sens, ainsi que la fonction setElement

	incrementArraySize(&TAB, 10);
	//displayElements(&TAB, 0, TAB.size);						// la fonction incrementArraySize a fonctionné, on a bien 10 zéros de plus que sur les autres 

	
	// on enlève des éléments de la 14e position à la TAILLEINITIALE-ème, sachant qu'avaec le incrementArraySize, le tableau fait TAILLEINITIALE+10
	// décommentez le deleteElements que vous voulez tester : celui à l'endroit (1) ou à l'envers (2)

	//deleteElements(&TAB, 10, TAB.size-1);	
	deleteElements(&TAB, 20, 15);

	//printf("\ntaille tableau = %d, eltscount = %d", TAB.size, TAB.eltsCount);
	displayElements(&TAB, 0, TAB.size - 1);
	

			

	
}