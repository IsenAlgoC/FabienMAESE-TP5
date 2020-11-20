#pragma once
#include <stdio.h>
#include <stdlib.h>

int initTab(int* tab, int size); 
// ^fonction qui remplit un tableau d'entiers de taille "size" avec des zéros

int afficheTab(int* tab, int size, int nbElts);
// ^fonction qui afficher les nbElts premiers éléments du tableau 