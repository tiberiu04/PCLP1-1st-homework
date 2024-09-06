#include <stdio.h>
#include <math.h>

//subprogram pentru a trece din baza 8 in 10
unsigned long long conversionbase(unsigned long long x)
{
	unsigned long long p = 1, newnum = 0;
	while (x > 0) {
		newnum = newnum + (x % 10) * p;
		p = p * 8;
		x = x / 10;
	}
	return newnum;
}

int main(void)
{
	long long max1a = -1, max1b = -1, max_a = -1, max_b = -1, n, i;
	unsigned long long a, b, ps = 0;
	double n_a, n_b, sumsqra = 0, sumsqrb = 0;

	scanf("%lld", &n);
	for (i = 0; i < n; i++) {
		//citesc coordonatele
		scanf("%llu %llu", &a, &b);
		//convertesc in baza 10
		a = conversionbase(a);
		b = conversionbase(b);
		//calculez produsul scalar
		ps = ps + (a * b);
		//calculez suma patratelor pt norma
		sumsqra += a * a;
		sumsqrb += b * b;
		//calculez cel de al doilea maxim
		if (max1a < (long long)a) {
			max_a = max1a;
			max1a = (long long)a;
		} else if (max_a < (long long)a && (long long)a < max1a) {
			max_a = (long long)a;
		}
		if (max1b < (long long)b) {
			max_b = max1b;
			max1b = (long long)b;
		} else if (max_b < (long long)b && (long long)b < max1b) {
			max_b = (long long)b;
		}
	}
	//calculez normele
	n_a = sqrt(1.0L * sumsqra);
	n_b = sqrt(1.0L * sumsqrb);
	printf("%llu\n", ps);
	printf("%lld %lld\n", max_a, max_b);
	printf("%0.7lf %0.7lf\n", n_a, n_b);
	return 0;
}
