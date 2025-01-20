#include <stdio.h>

float x[200];
float y[200];
int m;
float theta0 = 1.000;
float theta1 = 1.000;

float grad0() {
    float sum = 0;
    for(int i = 0; i < m; i++) sum += (theta0 + theta1 * x[i] - y[i]);
    sum /= m;
    return sum;
}

float grad1() {
    float sum = 0;
    for(int i = 0; i < m; i++) sum += (theta0 + theta1 * x[i] - y[i]) * x[i];
    sum /= m;
    return sum;
}

int main() {
    scanf("%d", &m);
    for(int i = 0; i < m; i++)  {
        scanf("%f", &x[i]);
        scanf("%f", &y[i]);
    }
    int T = 2000;
    float alpha = 0.01;
    while(T--) {
        float g0 = grad0();
        float g1 = grad1();
        theta1 -= alpha * g1;
        theta0 -= alpha * g0;
    }
    printf("y = %.3f + %.3fx", theta0, theta1);
    return 0;
}