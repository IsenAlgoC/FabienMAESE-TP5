#include "tab2.h"

int main() {

	TABLEAU TAB=newArray();

	displayElements(&TAB, 0, 30);
	setElement(&TAB, 15, 7);
	displayElements(&TAB, 0, 30);
	displayElements(&TAB, 30, 20);				// la fonction displayElement fonction bien dans les deux sens 

}