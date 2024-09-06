#include <stdio.h>
#include <stdlib.h>

void read_matrix(int n, int a[][1000])
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	}
}

void parcurgere_mat(int n, int a[][1000])
{
	long long  i, j, distanta = 0, x;
	i = 0;
	j = 0;
	while (a[i][j] != 0) {
	//in while parcurgem matricea pana ajungem la un element=0
		if (i % 2 == j % 2) { //conditia pentru patrat alb
			//distanta parcursa
			distanta += abs(a[i][j] - 0);
			x = a[i][j];
			a[i][j] = 0;//marcam cu 0 fiindca gigel a trecut pe acolo
			//parcurg coloanele de pe linia i si pun %n daca iese din matrice
			j = (j + x) % n;
			if (j < 0)
				j = j + n;
			//adaug n ca a mers in stanga si a iesit
		} else { //facem prelucrarile pentru patrat negru
			distanta += abs(a[i][j] - 0);
			x = a[i][j];
			a[i][j] = 0;
			//parcurg liniile de pe coloana j si pun %n
			i = (i + x) % n;
			//verific daca modulo n este negativ adaug un n
			if (i < 0)
				i = i + n;
		}
	}
	printf("%lli\n", distanta); //afisez distanta
	//daca j<26 atunci vom afisa j+'A'
	if (j < 26) {
		char c = j + 'A';
		printf("%lld %c\n", n - i, c);
	} else if (j > 25 && j < 702) {
		//cand j este intre 25 si 702 trebuie sa afisam doua litere
		printf("%lld ", n - i);
		char c, d;
		c = (j / 26) - 1 + 'A';
		d = j % 26 + 'A';
		printf("%c", c);
		printf("%c\n", d);
	} else { //vom afisa 3 litere ca la excel cand trece peste ZZ.
		printf("%lld", n - i);
		printf("A");
		//afisam A pentru ca sunt 676 combinatii in care A este prima litera
		//noi suntem intre 701 si 1000,adica nu ar putea trece de un AXX
		char c, d; //c, d reprezinta literele care trebuie afisate
		j = j - 676;
		c = (j / 26) - 1 + 'A';
		d = j % 26 + 'A';
		printf("%c", c);
		printf("%c\n", d);
	}
}

int main(void)
{
	int n, a[1000][1000];
	scanf("%d", &n);//citesc n
	read_matrix(n, a);
	parcurgere_mat(n, a); //apelez functia care face parcurgerea
	return 0;
}
