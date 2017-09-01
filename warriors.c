/* Copyright 2017 Stroinea Ioana */
#include <stdio.h>
#include <stdlib.h>
#define MAX 999999999;

// calculeaza maximul dintre doua numere
int funcMax(int x, int y) {
	if(x > y)
		return x;
	else
		return y;
}

int warriors(int levels, int lives, int** helper) {
	int max;
	int i, j, k;
	
	// initializare matrice cu valoarea maxima
	for(i = 0; i < lives + 1; i++)
		for(j = 0; j < levels + 1; j++)	
			helper[i][j] = MAX;

		for(i = 0; i < lives + 1; i++)
		for(j = 0; j < levels + 1; j++) {
			// pentru 0 vieti si 0 nivele am nevoie de 0 incercari
			if(i == 0 && j == 0)
				helper[i][j] = 0;
			// pentru i vieti si 0 nivele am nevoie de 0 incercari
			else if(i != 0 && j == 0)
				helper[i][j] = 0;
			// pentru 0 vieti si j nivele am nevoie de 0 incercari
			else if(i == 0 && j != 0)
				helper[i][j] = 0;
			// pentru o viata si j nivele am nevoie de j incercari
			else if(i == 1 && j != 0)
				helper[i][j] = j;
		}

	for(i = 2; i < lives + 1; i++)
		for(j = 2; j < levels + 1; j++) {
				/* testez toate incercarile pana la nivelul actual
				si selectez valoarea minima la care se adauga 1 pentru
				nivelul actual */
				for(k = 1; k < j + 1; k++){
					max = funcMax(helper[i - 1][k - 1], helper[i][j - k]) + 1;
					if(helper[i][j] > max)
						helper[i][j] = max;
				}
		}
	// rezltatul se afla in ultima celula din matrice
	return helper[lives][levels];
}

int main(int argc, char* argv[]) {
	FILE* fin = fopen("warriors.in", "r");
	FILE*  fout = fopen("warriors.out", "w");

	int levels, lives;
	int min;
	int i;

	// citire nivele si vieti din fisier
	fscanf(fin, "%d %d", &levels, &lives);

	// alocare matrice
	int** helper = (int **)malloc((lives + 1) * sizeof(int*));
	for(i = 0; i < lives + 1; i++)
		helper[i] = (int *)malloc((levels + 1) * sizeof(int));

	min = warriors(levels, lives, helper);
	fprintf(fout, "%d\n", min);

	return 0;
}
