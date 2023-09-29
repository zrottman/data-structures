// Demo of heap functionality using 2022 Advent of Code 
// problem Day 1, Part 2 (adventofcode.com/2022/day/1)

#include <stdio.h>
#include <stdlib.h>
#include "../src/Heap.h"

int main() {
    FILE* fp;
    char  c;
    char  last;
    char  buf[32];
    int   cur_sum;
    int   total;
    int   polled;
    int   i;
    Heap* maxheap;

    // init maxheap
    maxheap = heap_construct();
    
    // open input file
    fp = fopen("demos/data/advent2022_01", "r");

    // parse file
    cur_sum = 0;
    i = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            if (last == '\n') {
                // on blank line, insert cur_sum into maxheap
                heap_insert(maxheap, cur_sum);
                cur_sum = 0;
            } else {
                // on line end, parse buf as int and add to cur_sum
                buf[i] = '\0';
                cur_sum += atoi(buf);
                i = 0;
            }
        } else {
            buf[i++] = c;
        }
        last = c;
    }

    // close file
    fclose(fp);

    // poll maxheap for top 3 values
    total = 0;
    printf("Top three calorie quantities:\n");
    for (int i=0; i<3; ++i) {
        poll(maxheap, &polled);
        printf(" %d: %d\n", i+1, polled);
        total += polled;
    }
    printf("Total: %d\n\n", total);
    heap_destroy(&maxheap);
}
