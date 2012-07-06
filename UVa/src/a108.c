#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

#ifndef ONLINE_JUDGE
#include"a108.h"
#endif

extern int* kadane_algorithm(int array[], int len);
extern int max_sum(int array[], int N);

int main(int argc, char *argv[])
{
    int n = 0;
    if (!scanf("%d", &n)) {
        return EXIT_FAILURE;
    }

    int array[n * n];

    int value = 0;
    int i = 0;
    while (i < n * n) {
		scanf("%d", &value);
        array[i++] = value;
    }

	int sum = max_sum(array, n);
	printf("%d\n", sum);

    return EXIT_SUCCESS;
}

int max_sum(int array[], int n)
{
    int matrix[n][n];
	int prefix_column[n][n];

    int i = 0;
	for (; i < n * n; i++) {
		int x = i / n;
		int y = i % n;
		matrix[x][y] = array[i];
		prefix_column[x][y] = matrix[x][y];
		if (x) {
			prefix_column[x][y] += prefix_column[x - 1][y];
		}
	}

#ifdef DEBUG
    printf("Input Matrix\n");
    int x = 0;
    for (; x < n; x++) {
        int y = 0;
        for (; y < n; y++) {
            printf("%10d", matrix[x][y]);
        }
        printf("\n");
    }
    printf("\n");
#endif

	int	max_sum = INT_MIN;
	i = 0;
	for(; i < n; i++) {
		int j;
		for(j = i; j < n; j++) {
			int sum = 0;
			int k = 0;
			for(; k < n; k++) {
				sum += prefix_column[j][k];
				if (i) {
					sum -= prefix_column[i - 1][k];
				}
				if(sum > max_sum) {
					max_sum = sum;
				}
				if (sum < 0) {
					sum = 0;
				}
			}
		}
	}

#ifdef DEBUG
    printf("Vertical Prefix Sum\n");
    for (x = 0; x < n; x++) {
        int y = 0;
        for (; y < n; y++) {
            printf("%10d", prefix_column[x][y]);
        }
        printf("\n");
    }
    printf("\n");
#endif

	return max_sum;
}
