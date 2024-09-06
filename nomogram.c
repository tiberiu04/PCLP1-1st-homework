#include <stdio.h>

int main(void)
{
	int n, m, t, i, j, k, l, i1, col, ok, ok1, a[101][101];
	long lines[101][101], columns[101][101], x;
	long long nrde1, numberofones[101][101], numberofones1[101][101];

	scanf("%d", &t);
	for (i1 = 0; i1 < t; i1++) {
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++) {
			scanf("%d", &k);
			for (j = 0; j < k; j++)
				scanf("%ld", &lines[i][j]); // citire restrictii linii
		}
		for (i = 0; i < m; i++) {
			scanf("%d", &k);
			for (j = 0; j < k; j++)
				scanf("%ld", &columns[i][j]); // citire restrictii coloane
		}
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				scanf("%d", &a[i][j]); // citire matrice a
		ok = 1;
		for (i = 0; i < n; i++) {
			nrde1 = 0;
			col = 0;
			for (j = 0; j <= m; j++) {
			//numar cati de 1 sunt pe linie
				if (a[i][j] == 1) {
					nrde1++;
				} else if (a[i][j] == 0 && nrde1 != 0) {
					//memorez intr-o matrice nr de 1 dintr un grup
					numberofones[i][col] = nrde1;
					//col este pt a contoriza coloanele matricii noi
					col++;
					nrde1 = 0;
				}
			}
			for (l = 0; l < col; l++) {
				x = lines[i][l];
				//verific restrictiile pe linii daca sunt bune
				if (numberofones[i][l] != x && numberofones[i][l] > 0)
					ok = 0;//in caz negativ
			}
		}
		ok1 = 1;
		for (j = 0; j < m; j++) {
			nrde1 = 0;
			col = 0;
			for (i = 0; i <= n; i++) {
				//numar cati de 1 sunt pe coloana
				if (a[i][j] == 1) {
					nrde1++;
				} else if (a[i][j] == 0 && nrde1 != 0) {
					//memorez intr-o alta matrice nr de 1 dintr un grup
					numberofones1[j][col] = nrde1;
					col++;
					nrde1 = 0;
				}
			}
			for (l = 0; l < col; l++) {
				x = columns[j][l];
				//verific restrictiile pe coloane daca sunt bune
				if (numberofones1[j][l] != x && numberofones1[j][l] > 0)
					ok1 = 0; //in caz negativ ok1=0
			}
		}
		//daca s au respectat restrictiile afisez Corect
		if (ok == ok1 && ok == 1) {
			printf("Corect");
			printf("\n");
		} else {//altfel afisez Eroare
			printf("Eroare");
			printf("\n");
		}
	}
	return 0;
}
