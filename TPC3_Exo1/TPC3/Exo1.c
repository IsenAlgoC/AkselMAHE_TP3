#include <stdlib.h>
#include <stdio.h>
#define carre(x) (x)* (x)

void main() {
	int Nb = 5;
	printf("Le carr� de Nb est %i", carre(Nb));
	printf("\nCarre(Nb+1)=%i", carre(Nb+1));  //mettre les parenth�ses � (x) * (x) pour les priorit�s de calcul 
}