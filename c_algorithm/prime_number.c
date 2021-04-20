#include <stdio.h>
#include <math.h>

// 정의에 의해 소수를 구하는 프로그램
int is_prime (int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0)  { return 0; }
    }    
    return 1;
}

// 개선
// 그러나 sqrn()함수는 실수형의 데이ㅓ를 인자로 받아서 실수형의 리턴값을 내놓는 실수를 취급하는 수학 함수 이기 때문에,
// 정수형함수(is_prime)처럼 빠른 속도를 내라고 하는 것은 어리석다.
int is_prime2 (int n) {
    int sqrn = (int)sqrt(n);
    for (int i = 2; i <= sqrn; i++) {
        if (n % i == 0)  { return 0; }
    }    
    return 1;
}

// is_prime2 : 기본적인 실행 시간은 길지만, 주어진 값 대소에 관계없이 고른 속력을 나타낸다.

int main (void) {
    int n;

    while (1) {
        puts("\nInput number to test -> ");
        scanf("%d", &n);

        if (n < 0) { continue; }
        if (n == 0) { break; }

        printf("\n Ans: %d is %s prime number", n, is_prime2(n) ? "" : "not");
    }
}