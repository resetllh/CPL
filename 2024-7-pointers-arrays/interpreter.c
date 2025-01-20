#include <stdio.h>

int main() {
    long x;
    scanf("%x", &x);
    int *p = (int*)&x;
    unsigned *q = (unsigned*)&x;
    float* f = (float*)&x;
    printf("%d\n", *p);
    printf("%u\n", *q);
    printf("%.6f\n", *f);
    printf("%.3e", *f);
    return 0;
}