#pragma once
#include <stdio.h>
#include <stdlib.h>

int initTab(int* tab, int size); 
// ^fonction qui remplit un tableau d'entiers de taille "size" avec des z�ros

int afficheTab(int* tab, int size, int nbElts);
// ^fonction qui afficher les nbElts premiers �l�ments du tableau 