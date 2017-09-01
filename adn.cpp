/* Copyright 2017 Stroinea Ioana */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void adn(FILE* fin, FILE*  fout, char* x, char* y, char* z, char* a, char* b){

	int lines;
	int nr;
	int ct = 1;
	int i, j, k, l;
	int ok;
	int** matrix;
	int*** trei;
	int**** patru;

	fscanf(fin, "%d", &lines);

	while(ct <= lines){
		ok = 0;
		fscanf(fin, "%d", &nr);

		if(nr == 1){
			fscanf(fin, "%s %s", x, z);
			//fprintf(fout, "%d %s %s\n", nr, x, z);
		}
		if(nr == 2){
			fscanf(fin, "%s %s %s", x, y, z);
			matrix =  new int*[strlen(x) + 1];
			for(i = 0; i <= strlen(x); i++){
				matrix[i] = new int[strlen(y) + 1];
			}
		}
		if(nr == 3){
			fscanf(fin, "%s %s %s %s", x, y, a, z);
			trei =  new int**[strlen(x) + 1];
			for(i = 0; i <= strlen(x); i++){
				trei[i] = new int*[strlen(y) + 1];
				for(j = 0; j <= strlen(y); j++)
					trei[i][j] = new int[strlen(a) + 1];
			}
		}

		if(nr == 4){
			fscanf(fin, "%s %s %s %s %s", x, y, a, b, z);
			patru =  new int***[strlen(x) + 1];
			for(i = 0; i <= strlen(x); i++){
				patru[i] = new int**[strlen(y) + 1];
				for(j = 0; j <= strlen(y); j++){
					patru[i][j] = new int*[strlen(a) + 1];
					for(k = 0; k <= strlen(b); k++)
						patru[i][j][k] = new int[strlen(b) + 1];
				}
			}
		}

		switch(nr){
			case 1:
				if(strlen(x) != strlen(z)){
					fprintf(fout, "%d\n", 0);
				} else if(strlen(x) == strlen(z)){
					for(i = 0; i < strlen(x); i++){
						if(x[i] == z[i])
							ok++;
					}
					if(ok == strlen(x)){
						fprintf(fout, "%d\n", 1);
					} else {
						fprintf(fout, "%d\n", 0);
					}
				}
				break;
				
			case 2:
				for(i = 0; i <= strlen(x); i++){
					for(j = 0; j <= strlen(y); j++)
						matrix[i][j] = 0;
				}
				if(strlen(x) + strlen(y) != strlen(z)){
					fprintf(fout, "%d\n", 0);
				} else {
					matrix[0][0] = 1;
					for(i = 0; i <= strlen(x); i++)
						for(j = 0; j <= strlen(y); j++){
							if(i == 0 && j== 0)
								continue;
							else if(i == 0 && y[j - 1] == z[j - 1])
								matrix[i][j] = matrix[i][j - 1];
							else if(j == 0 && x[i - 1] == z[i - 1])
								matrix[i][j] = matrix[i - 1][j];
							else if(x[i - 1] == z[i + j -1]) {
								if(y[j - 1] != z[i + j - 1])
									matrix[i][j] = matrix[i - 1][j];
								else if(y[j - 1] == z[i + j - 1]){
									if(matrix[i - 1][j] == 1)
										matrix[i][j] = 1;
									else if(matrix[i][j - 1] == 1)
								 		matrix[i][j] = 1;
									else
										matrix[i][j] = 0;
								}
							}
							else if(y[j - 1] == z[i + j -1]){
								if(x[i - 1] != z[i + j - 1])
									matrix[i][j] = matrix[i][j - 1];
							}
						}
					fprintf(fout, "%d\n", matrix[strlen(x)][strlen(y)]);
				}
					break;
			case 3:
				for(i = 0; i <= strlen(x); i++){
					for(j = 0; j <= strlen(y); j++)
						for(k = 0; k <= strlen(a); k++)
							trei[i][j][k] = 0;
				}
				if(strlen(x) + strlen(y) + strlen(a) != strlen(z)){
					fprintf(fout, "%d\n", 0);
				} else {
					trei[0][0][0] = 1;
					for(i = 0; i <= strlen(x); i++){
						for(j = 0; j <= strlen(y); j++)
							for(k = 0; k <= strlen(a); k++){
								if(i == 0 && j==0 & k==0)
									continue;
								else if(i == 0 && j == 0 && a[k - 1] == z[k - 1])
									trei[i][j][k] = trei[i][j][k - 1];
								else if(i == 0 && k == 0 && y[j - 1] == z[j - 1])
									trei[i][j][k] = trei[i][j - 1][k];
								else if(j == 0 && k == 0 && x[i - 1] == z[i - 1])
									trei[i][j][k] = trei[i - 1][j][k];
								else if(i == 0 && y[j - 1] != z[i + j + k -1] && a[k - 1] == z[i + j + k -1])
									trei[i][j][k] = trei[i][j][k - 1];
								else if(i == 0 && y[j - 1] == z[i + j + k -1] && a[k - 1] != z[i + j + k -1])
									trei[i][j][k] = trei[i][j - 1][k];
								else if(j == 0 && x[i - 1] != z[i + j + k -1] && a[k - 1] == z[i + j + k -1])
									trei[i][j][k] = trei[i][j][k - 1];
								else if(j == 0 && x[i - 1] == z[i + j + k -1] && a[k - 1] != z[i + j + k -1])
									trei[i][j][k] = trei[i - 1][j][k];
								else if(k == 0 && x[i - 1] != z[i + j + k -1] && y[j - 1] == z[i + j + k -1])
									trei[i][j][k] = trei[i][j - 1][k];
								else if(k == 0 && x[i - 1] == z[i + j + k -1] && y[j - 1] != z[i + j + k -1])
									trei[i][j][k] = trei[i - 1][j][k];
								else if(x[i - 1] == z[i + j + k -1] && y[j - 1] != z[i + j + k -1] && a[k - 1] != z[i + j + k -1])
									trei[i][j][k] = trei[i - 1][j][k];
								else if(x[i - 1] != z[i + j + k -1] && y[j - 1] == z[i + j + k -1] && a[k - 1] != z[i + j + k -1])
									trei[i][j][k] = trei[i][j - 1][k];
								else if(x[i - 1] != z[i + j + k -1] && y[j - 1] != z[i + j + k -1] && a[k - 1] == z[i + j + k -1])
									trei[i][j][k] = trei[i][j][k - 1];
								else if(x[i - 1] == z[i + j + k -1] && y[j - 1] == z[i + j + k -1] && a[k - 1] != z[i + j + k -1])
									trei[i][j][k] = trei[i - 1][j][k] || trei[i][j - 1][k] ;
								else if(x[i - 1] == z[i + j + k -1] && y[j - 1] != z[i + j + k -1] && a[k - 1] == z[i + j + k -1])
									trei[i][j][k] = trei[i - 1][j][k] || trei[i][j][k - 1] ;
								else if(x[i - 1] != z[i + j + k -1] && y[j - 1] == z[i + j + k -1] && a[k - 1] == z[i + j + k -1])
									trei[i][j][k] = trei[i][j][k - 1] || trei[i][j - 1][k] ;
								else if(x[i - 1] == z[i + j + k -1] && y[j - 1] == z[i + j + k -1] && a[k - 1] == z[i + j + k -1])
									trei[i][j][k] = trei[i][j][k - 1] || trei[i][j - 1][k] || trei[i - 1][j][k];
							}
						}
						fprintf(fout, "%d\n", trei[strlen(x)][strlen(y)][strlen(a)]);
					}
				break;
			case 4:
				for(i = 0; i <= strlen(x); i++){
					for(j = 0; j <= strlen(y); j++)
						for(k = 0; k <= strlen(a); k++)
							for(l = 0; l <= strlen(b); l++)
								patru[i][j][k][l] = 0;
				}
				if(strlen(x) + strlen(y) + strlen(a) + strlen(b) != strlen(z)){
					fprintf(fout, "%d\n", 0);
				} else {
					patru[0][0][0][0] = 1;
					for(i = 0; i <= strlen(x); i++){
						for(j = 0; j <= strlen(y); j++)
							for(k = 0; k <= strlen(a); k++)
								for(l = 0; l <= strlen(b); l++){
								if(i == 0 && j == 0 & k == 0 && l == 0)
									continue;
								else if(i == 0 && j == 0 && k == 0 && b[l - 1] == z[l - 1])
									patru[i][j][k][l] = patru[i][j][k][l - 1];
								else if(i == 0 && j == 0 && l == 0 && a[k - 1] == z[k - 1])
									patru[i][j][k][l] = patru[i][j][k - 1][l];
								else if(i == 0 && k == 0 && l == 0 && y[j - 1] == z[j - 1])
									patru[i][j][k][l] = patru[i][j - 1][k][l];
								else if(j == 0 && k == 0 && l == 0 && x[i - 1] == z[i - 1])
									patru[i][j][k][l] = patru[i - 1][j][k][l];
								else if(i == 0 && j == 0 && a[k - 1] != z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k][l - 1];
								else if(i == 0 && j == 0 && a[k - 1] == z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k - 1][l];
								else if(i == 0 && j == 0 && a[k - 1] == z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k][l - 1] || patru[i][j][k - 1][l];
								else if(i == 0 && k == 0 && y[j - 1] != z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k][l - 1];
								else if(i == 0 && k == 0 && y[j - 1] == z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l];
								else if(i == 0 && k == 0 && y[j - 1] == z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k][l - 1] || patru[i][j - 1][k][l];
								else if(j == 0 && k == 0 && x[i - 1] != z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k][l - 1];
								else if(j == 0 && k == 0 && x[i - 1] == z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l];
								else if(j == 0 && k == 0 && x[i - 1] == z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l] || patru[i][j][k][l - 1];
								else if(i == 0 && l == 0 && y[j - 1] != z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k - 1][l];
								else if(i == 0 && l == 0 && y[j - 1] == z[i + j + k + l - 1] && a[k - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l];
								else if(i == 0 && l == 0 && y[j - 1] == z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l] || patru[i][j][k - 1][l];
								else if(j == 0 && l == 0 && x[i - 1] != z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k - 1][l];
								else if(j == 0 && l == 0 && x[i - 1] == z[i + j + k + l - 1] && a[k - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l];
								else if(j == 0 && l == 0 && x[i - 1] == z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l] || patru[i][j][k - 1][l];
								else if(k == 0 && l == 0 && x[i - 1] != z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l];
								else if(k == 0 && l == 0 && x[i - 1] == z[i + j + k + l - 1] && y[j - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l];
								else if(k == 0 && l == 0 && x[i - 1] == z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l] || patru[i][j - 1][k][l];
								else if(i == 0 && y[j - 1] != z[i + j + k + l - 1] && a[k - 1] != z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k][l - 1];
								else if(i == 0 && y[j - 1] != z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k - 1][l];
								else if(i == 0 && y[j - 1] == z[i + j + k + l - 1] && a[k - 1] != z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l];
								else if(i == 0 && y[j - 1] != z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k - 1][l] || patru[i][j][k][l - 1];
								else if(i == 0 && y[j - 1] == z[i + j + k + l - 1] && a[k - 1] != z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l] || patru[i][j][k][l - 1];
								else if(i == 0 && y[j - 1] == z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k - 1][l] || patru[i][j - 1][k][l];
								else if(i == 0 && y[j - 1] == z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k - 1][l] || patru[i][j - 1][k][l] || patru[i][j][k][l - 1];
								else if(j == 0 && x[i - 1] != z[i + j + k + l - 1] && a[k - 1] != z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k][l - 1];
								else if(j == 0 && x[i - 1] != z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k - 1][l];
								else if(j == 0 && x[i - 1] == z[i + j + k + l - 1] && a[k - 1] != z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l];
								else if(j == 0 && x[i - 1] != z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k][l - 1] || patru[i][j][k - 1][l];
								else if(j == 0 && x[i - 1] == z[i + j + k + l - 1] && a[k - 1] != z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l] || patru[i][j][k][l - 1];
								else if(j == 0 && x[i - 1] == z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l] || patru[i][j][k - 1][l];
								else if(j == 0 && x[i - 1] == z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k - 1][l] || patru[i - 1][j][k][l] || patru[i][j][k][l - 1];
								else if(k == 0 && x[i - 1] != z[i + j + k + l - 1] && y[j - 1] != z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k][l - 1];
								else if(k == 0 && x[i - 1] != z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l];
								else if(k == 0 && x[i - 1] == z[i + j + k + l - 1] && y[j - 1] != z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l];
								else if(k == 0 && x[i - 1] != z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k][l - 1] || patru[i][j - 1][k][l];
								else if(k == 0 && x[i - 1] == z[i + j + k + l - 1] && y[j - 1] != z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l] || patru[i][j][k][l - 1];
								else if(k == 0 && x[i - 1] == z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l] || patru[i][j - 1][k][l];
								else if(k == 0 && x[i - 1] == z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l] || patru[i - 1][j][k][l] || patru[i][j][k][l - 1];
								else if(l == 0 && x[i - 1] != z[i + j + k + l - 1] && y[j - 1] != z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k - 1][l];
								else if(l == 0 && x[i - 1] != z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1] && a[k - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l];
								else if(l == 0 && x[i - 1] == z[i + j + k + l - 1] && y[j - 1] != z[i + j + k + l - 1] && a[k - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l];
								else if(l == 0 && x[i - 1] != z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k - 1][l] || patru[i][j - 1][k][l];
								else if(l == 0 && x[i - 1] == z[i + j + k + l - 1] && y[j - 1] != z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l] || patru[i][j][k - 1][l];
								else if(l == 0 && x[i - 1] == z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1] && a[k - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l] || patru[i][j - 1][k][l];
								else if(l == 0 && x[i - 1] == z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1] && a[k - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l] || patru[i - 1][j][k][l] || patru[i][j][k - 1][l];
								else if(x[i - 1] != z[i + j + k + l - 1] && y[j - 1] != z[i + j + k + l - 1]
									&& a[k - 1] != z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k][l - 1];
								else if(x[i - 1] != z[i + j + k + l - 1] && y[j - 1] != z[i + j + k + l - 1]
									&& a[k - 1] == z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k - 1][l];
								else if(x[i - 1] != z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1]
									&& a[k - 1] != z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l];
								else if(x[i - 1] == z[i + j + k + l - 1] && y[j - 1] != z[i + j + k + l - 1]
									&& a[k - 1] != z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l];
								else if(x[i - 1] != z[i + j + k + l - 1] && y[j - 1] != z[i + j + k + l - 1]
									&& a[k - 1] == z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k][l - 1] || patru[i][j][k - 1][l];
								else if(x[i - 1] != z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1]
									&& a[k - 1] != z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k][l - 1] || patru[i][j - 1][k][l];
								else if(x[i - 1] == z[i + j + k + l - 1] && y[j - 1] != z[i + j + k + l - 1]
									&& a[k - 1] != z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j][k][l - 1] || patru[i - 1][j][k][l];
								else if(x[i - 1] != z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1]
									&& a[k - 1] == z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l] || patru[i][j][k - 1][l];
								else if(x[i - 1] == z[i + j + k + l - 1] && y[j - 1] != z[i + j + k + l - 1]
									&& a[k - 1] == z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l] || patru[i][j][k - 1][l];
								else if(x[i - 1] == z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1]
									&& a[k - 1] != z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l] || patru[i - 1][j][k][l];
								else if(x[i - 1] != z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1]
									&& a[k - 1] == z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l] || patru[i][j][k - 1][l] || patru[i][j][k][l - 1];
								else if(x[i - 1] == z[i + j + k + l - 1] && y[j - 1] != z[i + j + k + l - 1]
									&& a[k - 1] == z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i - 1][j][k][l] || patru[i][j][k - 1][l] || patru[i][j][k][l - 1];
								else if(x[i - 1] == z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1]
									&& a[k - 1] != z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l] || patru[i - 1][j][k][l] || patru[i][j][k][l - 1];
								else if(x[i - 1] == z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1]
									&& a[k - 1] == z[i + j + k + l - 1] && b[l - 1] != z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l] || patru[i][j][k - 1][l] || patru[i - 1][j][k][l];
								else if(x[i - 1] == z[i + j + k + l - 1] && y[j - 1] == z[i + j + k + l - 1]
									&& a[k - 1] == z[i + j + k + l - 1] && b[l - 1] == z[i + j + k + l - 1])
									patru[i][j][k][l] == patru[i][j - 1][k][l] || patru[i][j][k - 1][l] || patru[i][j][k][l - 1]
								|| patru[i - 1][j][k][l];
							}
						}
						fprintf(fout, "%d\n", patru[strlen(x)][strlen(y)][strlen(a)][strlen(b)]);
					}
				break;
		}
		ct++;
	}

}

int main(int argc, char* argv[]){
	FILE* fin = fopen(argv[1], "r");
	//FILE* fin = fopen("adn.in", "r");
	FILE*  fout = fopen("adn.out", "w");

	char x[1000];
	char y[1000];
	char z[1000];
	char a[1000];
	char b[1000];

	adn(fin, fout, x, y, z, a, b);

	return 0;
}