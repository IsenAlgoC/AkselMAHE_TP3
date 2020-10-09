#include <stdlib.h>
#include <stdio.h>
#define carre(x) (x)* (x)

void main() {
	int Nb = 5;
	printf("Le carré de Nb est %i", carre(Nb));
	printf("\nCarre(Nb+1)=%i", carre(Nb+1));  //mettre les parenthèses à (x) * (x) pour les priorités de calcul 
}