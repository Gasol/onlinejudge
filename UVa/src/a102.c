#include<stdlib.h>
#include<stdio.h>

#ifndef ONLINE_JUDGE
#include"a102.h"
#endif

#define B 0
#define G 1
#define C 2

typedef struct {
    int brown;
    int green;
    int clear;
} Bin;

int main(int argc, char *argv[])
{
    char *color_text[] = {"GCB", "GBC", "CGB", "CBG", "BGC", "BCG"};
    int rules[][3] = {{G, C, B},
                      {G, B, C},
                      {C, G, B},
                      {C, B, G},
                      {B, G, C},
                      {B, C, G}};

    Bin bins[] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    while (scanf("%d %d %d %d %d %d %d %d %d",
                &bins[0].brown, &bins[0].green, &bins[0].clear,
                &bins[1].brown, &bins[1].green, &bins[1].clear,
                &bins[2].brown, &bins[2].green, &bins[2].clear) > 0) {

        int rules_count = sizeof(rules) / sizeof(int[3]);
        int bins_size = sizeof(bins) / sizeof(Bin);
        int min_move = 0;
        int index = -1;

        int i = 0;
        for (; i < rules_count; i++) {
            int move = 0;
            int j = 0;
            for (; j < bins_size; j++) {
                if (rules[i][j] == B) {
                    move += bins[j].green + bins[j].clear;
                }
                if (rules[i][j] == G) {
                    move += bins[j].brown + bins[j].clear;
                }
                if (rules[i][j] == C) {
                    move += bins[j].green + bins[j].brown;
                }
            }

            if (move <= min_move) {
                min_move = move;
                index = i;
            } else if (index < 0) {
                min_move = move;
                index = i;
            }
        }

        printf("%s %d\n", color_text[index], min_move);
    }

    return EXIT_SUCCESS;
}
