#include <stdio.h>

int main() {
    float G = 6.674e-11, M = 77.15, m ,R, F;
    scanf("%f %f", &m, &R);
    F = G * M * m / (R * R);
    printf("%.3e", F);
    return 0;
}