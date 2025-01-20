#include <stdio.h>
#include <math.h>

int main() {
    int p, q;
    scanf("%d %d", &p, &q);
    double p1 = p, q1 = q, x = 0;
    double y = pow(pow(q1 / 2, 2) + pow(p1 / 3, 3), 0.5);
    if(- q1 / 2 + y >= 0) {
        x += pow(- q1 / 2 + y, 1. / 3);
    }
    else {
        x -= pow(q1 / 2 - y, 1. / 3);
    }
    if(- q1 / 2 - y >= 0) {
        x += pow(- q1 / 2 - y, 1. / 3);
    }
    else {
        x -= pow(q1 / 2 + y, 1. / 3);
    }
    printf("%.3lf", x);
    return 0;
}