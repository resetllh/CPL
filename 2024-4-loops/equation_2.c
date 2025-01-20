#include <stdio.h>

double a[3][3];
double det() {
    double ans = 0;
    ans = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - 
          a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
          a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
    return ans;
}
int main() {
    double b[3][4];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            scanf("%lf", &b[i][j]);
        }
    }

    double d, d1, d2, d3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            a[i][j] = b[i][j];
        }
    }
    d = det();
    for(int i = 0; i < 3; i++) a[i][0] = b[i][3];
    d1 = det();
    for(int i = 0; i < 3; i++) {
        a[i][0] = b[i][0];
        a[i][1] = b[i][3];
    }
    d2 = det();
    for(int i = 0; i < 3; i++) {
        a[i][1] = b[i][1];
        a[i][2] = b[i][3];
    }
    d3 = det();

    printf("%.2lf %.2lf %.2lf", d1 / d, d2 / d, d3 / d);
    return 0;
}