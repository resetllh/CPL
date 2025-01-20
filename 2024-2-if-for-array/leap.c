#include <stdio.h>
int is_leap(long long n) {
    if((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    if(is_leap(n)) {
        printf("Leap year!\n");
    }
    else {
        printf("Normal year!\n");
    }
    if(is_leap(n % 400 + k % 400)) {
        printf("Leap year!");
    }
    else {
        printf("Normal year!");
    }
    return 0;
}