#pragma once
#include <stdio.h>
#include <stdlib.h>
#define TAB2SIZE 100
#define TAILLEAJOUT 50

int initTab(int* tab, int size);
// ^fonction qui remplit un tableau d'entiers de taille "size" avec des zéros

int afficheTab(int* tab, int size, int nbElts);
// ^fonction qui afficher les nbElts premiers éléments du tableau 

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element);
// ^fonction qui ajoute element dans un tableau déjà donné