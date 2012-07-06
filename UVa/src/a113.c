#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[])
{
	double n = 0;
	double p = 0;

	while (scanf("%lf %lf", &n, &p) != EOF) {
		printf("%.lf\n", pow(p, 1 / n));
	}

	return EXIT_SUCCESS;
}
