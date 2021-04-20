#include <stdio.h>

int is_prime (int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0)  { return 0; }
    }    
    return 1;
}

int main (void) {
    int n;

    while (1) {
        puts("\nInput number to test -> ");
        scanf("%d", &n);

        if (n < 0) { continue; }
        if (n == 0) { break; }

        printf("\n Ans: %d is %s prime number", n, is_prime(n) ? "" : "not");
    }
}