#include <stdio.h>
#include <math.h>

int n, p;
double epsilon = 1e-4;
int a[25];

double f(double x) {
    double ret = 0.;
    for(int i = n; i >= 0; i--) ret = x * ret + a[i];
    return pow(ret, p);
}

double simpos(double l, double r) {
    double p1 = f(l), p2 = f((l + r) / 2), p3 = f(r);
    return (4 * p2 + p1 + p3) / 6 * (r - l);
}

double adapt_simpos(double l, double r, double eps) {
    double mid = (l + r) / 2;
    double sl = simpos(l, mid), sr = simpos(mid, r), s = simpos(l, r);
    double err = sl + sr - s;
    if(err < 0) err = - err;
    if(err < 15 * eps)
        return sl + sr + (sl + sr - s) / 15;
    else
        return adapt_simpos(l, mid, eps / 2) + adapt_simpos(mid, r, eps / 2);
}

int main() {
    scanf("%d %d", &n, &p);
    for(int i = 0; i <= n; i++) scanf("%d", &a[i]);
    double l, r;
    scanf("%lf %lf", &l, &r);
    printf("%lf", adapt_simpos(l, r, epsilon));
    return 0;
}