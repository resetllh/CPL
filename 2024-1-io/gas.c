#include <stdio.h>
#include <math.h>

int main() {
    float P, L, n, R, T;
    R = 8.314;
    scanf("%f %f %f", &P, &L, &T);
    n = P * pow(L, 3) / (R * T);
    printf("%.4e", n);
    return 0;
}