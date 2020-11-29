#pragma once
#include <stdio.h>
#include <stdlib.h>
#define TAILLEINITIALE 40


typedef struct Tableau {
	int* elt; // le tableau d�entiers
	int size; // la taille de ce tableau d�entiers
	int eltsCount; // le nombre d��l�ments dans le tableau
} TABLEAU;


int initTab(TABLEAU tab);
// ^on r�utilise la fonction de l'exercice 1 qu'on modifie 

TABLEAU newArray();
// ^cr�e un nouveau TABLEAU en allouant une taille initiale pour les donn�es.

int incrementArraySize(TABLEAU* tab, int incrementValue);
// ^modifie la taille du tableau

int setElement(TABLEAU* tab, int pos, int element);
// ^�crit un �l�ment � une position donn�e sans insertion

int displayElements(TABLEAU* tab, int startPos, int endPos);
// ^affiche une portion du tableau de l�indice d�but � l�indice fin

int deleteElements(TABLEAU* tab, int startPos, int endPos);
// ^Met � jour le nombre d'�l�ments dans le tableau et diminue la taille du tableau. Supprime les �l�ments entre startPos et endPos (bornes comprises)

