#include <stdio.h>

//ordonare descrescatoare dupa cate credite obtine pana ajunge la 10
void sort_descending_arrays(int n, int v[100], int u[100])
{
	int i, j, aux, aux1;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if ((10 - v[i]) * u[i] < (10 - v[j]) * u[j]) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				aux1 = u[i];
				u[i] = u[j];
				u[j] = aux1;
			}
		}
	}
}

//calculez diferenta dintre nrdecredite si pmin din cerinta
int remainder_sum_of_credits(int n, int v[100], int u[100], int c)
{
	int i, s = 0;
	for (i = 0; i < n; i++)
		s = s + u[i] * v[i];
	if (s > c)
		return 0;
	else
		return c - s;
}

int main(void)
{
	int n, nota[100], cred[100], pmin, rez, position = 0, sol = 0, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &nota[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &cred[i]);
	scanf("%d", &pmin);
	//sortez notele si creditele
	sort_descending_arrays(n, nota, cred);
	rez = remainder_sum_of_credits(n, nota, cred, pmin);
	//caut cele mai mari numere pana ajung la pmin
	while (position < n && rez > 0) {
		rez = rez - (10 - nota[position]) * cred[position];
		sol++;
		position++;
	}
	//daca rez>0 adica nu ajung la pmin afisez -1
	if (rez > 0)
		printf("-1");
	else
		printf("%d", sol);
	return 0;
}
