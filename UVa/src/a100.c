#include<stdlib.h>
#include<stdio.h>
#include"a100.h"

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;

    while (scanf("%d %d", &i, &j) > 0) {
        printf("%d %d %d\n", i, j, max_cycle(i, j));
    }

    return EXIT_SUCCESS;
}

int max_cycle(int i, int j)
{
    int begin = 0;
    int end = 0;
    if (i > j) {
        begin = j;
        end = i;
    } else {
        begin = i;
        end = j;
    }

    int max = 0;
    int k = 0;
    for (k = begin; k < end + 1; k++) {
        int cycle = cycle_count(k);
        if (cycle > max) {
            max = cycle;
        }
    }

    return max;
}

int cycle_count(int num)
{
    int cycle = 1;

    while (num != 1) {
        if (num & 1) {
            num = 3 * num + 1;
        } else {
            num = num / 2;
        }
        cycle++;
    }

    return cycle;
}
