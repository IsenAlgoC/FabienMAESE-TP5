#include "tab2.h"

int main() {

	// dans ces tests, on a baiss� TAILLEINITIALE � 40 pour plus de clart� dans la console

	TABLEAU TAB=newArray();

	//displayElements(&TAB, 0, TAILLEINITIALE);				// newArray a bien fonctionn�

	for (int i = 0; i < TAB.size; i++) {
		setElement(&TAB, i, i+1);						// remplit le tableau de 1 � (TAB.size -1)
	}
		
	displayElements(&TAB, 0, TAB.size-1);		//dans la fonction display, on affiche les valeurs dans [startPos; endPos], or TAB->elt[TAB.size] n'existe pas
	//displayElements(&TAB, TAILLEINITIALE, 20);				// la fonction displayElement fonctionne bien dans les deux sens, ainsi que la fonction setElement

	incrementArraySize(&TAB, 10);
	//displayElements(&TAB, 0, TAB.size);						// la fonction incrementArraySize a fonctionn�, on a bien 10 z�ros de plus que sur les autres 

	
	// on enl�ve des �l�ments de la 14e position � la TAILLEINITIALE-�me, sachant qu'avaec le incrementArraySize, le tableau fait TAILLEINITIALE+10
	// d�commentez le deleteElements que vous voulez tester : celui � l'endroit (1) ou � l'envers (2)

	//deleteElements(&TAB, 10, TAB.size-1);	
	deleteElements(&TAB, 20, 15);

	//printf("\ntaille tableau = %d, eltscount = %d", TAB.size, TAB.eltsCount);
	displayElements(&TAB, 0, TAB.size - 1);
	

			

	
}