#pragma once
#include <stdio.h>
#include <stdlib.h>
#define TAILLEINITIALE 100


typedef struct Tableau {
	int* elt; // le tableau d’entiers
	int size; // la taille de ce tableau d’entiers
	int eltsCount; // le nombre d’éléments dans le tableau
} TABLEAU;


int initTab(TABLEAU tab);
// ^on réutilise la fonction de l'exercice 1 qu'on modifie 

TABLEAU newArray();
// ^crée un nouveau TABLEAU en allouant une taille initiale pour les données.

int incrementArraySize(TABLEAU* tab, int incrementValue);
// ^modifie la taille du tableau

int setElement(TABLEAU* tab, int pos, int element);
// ^écrit un élément à une position donnée sans insertion

int displayElements(TABLEAU* tab, int startPos, int endPos);
// ^affiche une portion du tableau de l’indice début à l’indice fin

int deleteElements(TABLEAU* tab, int startPos, int endPos);
// ^Met à jour le nombre d'éléments dans le tableau et diminue la taille du tableau. Supprime les éléments entre startPos et endPos (bornes comprises)

