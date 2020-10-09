#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NBMAXNOTES 30
#define square(a)  (a)*(a)

void main() {
	char saisie = 0;
	float tab[NBMAXNOTES], note, notemax, notemin, moyenne[NBMAXNOTES] = { 0 }, moy = 0, ECARTYPE = 0, NONOTES[NBMAXNOTES] = { 0 };
	int i, NBNOTES, abs = 0, NOTESVAL = 0, j, tmp;
	for (i = 0; i <= NBMAXNOTES - 1; i++) {
		tab[i] = -2;
	}
	i = 0;

	do {
		printf("\nEntrez la note no %i:  ", i + 1);
		scanf_s("%f", &note);
		if (note > 20 || note < 0) {
			do {
				printf("\nVous avez tapé une note invalide, l'eleve est-il (A)bsent ou voulez-vous arretez la saisie (O)ui (N)on ? ");
				saisie = _getch();
				saisie = toupper(saisie);

			} while (saisie != ('A') && saisie != ('O') && saisie != ('N'));
		}
		else {
			tab[i] = note;
			i++;
		}
		switch (saisie) {
		case 'A':
			tab[i] = -1;
			i++;
			break;
		}
	} while (saisie != 'O' && i < NBMAXNOTES);

	NBNOTES = i - 1;
	notemax = tab[0];
	notemin = tab[0];

	for (i = 0; i <= NBNOTES; i++) {
		if (tab[i] == -1) {
			abs++;
		}
		else if (tab[i] > notemax) {
			notemax = tab[i];
		}
		else if (tab[i] < notemin) {
			notemin = tab[i];
		}
	}

	for (i = 0; i <= NBNOTES; i++) {
		if (tab[i] != -1 && tab[i] != -2) {
			moyenne[NOTESVAL] = tab[i];
			NOTESVAL++;
		}
	}

	for (i = 0; i < NOTESVAL; i++) {
		moy = moyenne[i] + moy;
	}

	moy = moy / NOTESVAL;
	printf("La moyenne de ces %i notes est : %f", NOTESVAL, moy);



	printf("\nIl y a %i absences.", abs);

	for (i = 0; i <= NOTESVAL; i++) {
		ECARTYPE = square(moyenne[i] - moy) + ECARTYPE;
	}
	ECARTYPE = sqrt(ECARTYPE / (NOTESVAL - 1));
	printf("\nL'ecart-type vaut: %f", ECARTYPE);



	printf("\nLa plus grande note est %.2f\nLa plus petite note est %.2f\n", notemax, notemin);

	printf("\nNo note	Valeur note");
	for (i = 0; i < NOTESVAL; i++) {
		printf("\n%i	  %.2f; ", i + 1, moyenne[i]);
	}


	for (i = 0; i < NOTESVAL; i++)
	{
		for (j = i; j < NOTESVAL; j++)
		{
			if (moyenne[j] > moyenne[i])
			{
				tmp = moyenne[i];
				moyenne[i] = moyenne[j];
				moyenne[j] = tmp;
			}
		}

	}
	printf("\nRang	Valeur note");
	for (i = 0; i < NOTESVAL; i++) {
		printf("\n%i	  %.2f; ", i + 1, moyenne[i]);
	}
}















































