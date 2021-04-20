#include <stdio.h>
#include <alloca.h>
#include <stdlib.h>

#define MAX 9999

int main (void) {
    int* iptr;
    int i, j;

    iptr = (int*)calloc(MAX, sizeof(int)); // 메모리 할당과 초기화

    if (iptr == NULL) {
        puts("\n Memory allocation error !");
        exit(1);
    }

    for (i = 2; i < MAX; i++) {
        if (iptr[i] == 1) { continue; }

        j = i;
        while ((j += i) <= MAX) {
            iptr[j] = 1;
        }
    }

    for (i = 2; i < MAX; i++) {
        if (iptr[i] == 0) {
            printf("\t%6d", i);
        }
    }
}