#include <stdio.h>

// 유클리드 알고리즘
int get_gcd(int u, int v) {
    int t;

    while (u) {
        if (u < v) {
            t = u;
            u = v;
            v = t;
        }
        u = u - v;
    }

    return v;
}

int main (void) {
    int u, v;
    puts("\n get GCD of two positive interger");

    while(1) {
        scanf("%d %d", &u, &v);
        if (u < 0 || v < 0) { // 음수는 무효
            continue;
        }
        if (u == 0 || v == 0) { // 0이 입력되면 끝낸다.
            break;
        }
        printf("\n GCD of %d and %d is %d.", u, v, get_gcd(u, v));
    }
}