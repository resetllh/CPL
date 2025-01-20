#include <stdio.h>
#include <math.h>

float a[200];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    float max = 0;
    for(int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
        if(i == 0) max = a[0];
        else max = max > a[i] ? max: a[i];
    }
    for(int i = 0; i < n; i++) {
        a[i] -= max;
    }
    while(k--) {
        float tau;
        float var = 0;
        float sum = 0;
        scanf("%f", &tau);
        for(int i = 0; i < n; i++) {
            float yi = exp(a[i] / tau);
            sum += yi;
        }
        for(int i = 0; i < n; i++) {
            float yi = exp(a[i] / tau) / sum;
            printf("%.3f ", yi);
            var += 1. / n * pow(yi -  1. / n, 2);
        }
        printf("%.3f\n", var);
    }
}