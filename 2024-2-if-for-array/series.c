#include <stdio.h>
#include <math.h>

int main() {
    float x, ans=0;
    int n;
    scanf("%f %d", &x, &n);
    for(int i=0; i<= n; i++) {
        float term = (i % 2 == 0) ? 1 : -1;
        ans += term / (2 * i + 1) * x * pow(x * x, i);
    }
    printf("%.10f", 4 * ans);
    return 0;
}