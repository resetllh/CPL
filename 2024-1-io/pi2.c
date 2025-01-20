#include <stdio.h>
#include <math.h>

int main() {
    double pi1 = log(pow(5280, 3) * pow(236674 + 30303 * sqrt(61), 3) + 744) / sqrt(427);
    double pi2 = 4. * (6 * atan(1. / 8) + 2 * atan(1. / 57) + atan(1. / 239));
    printf("%.15lf\n%.15lf", pi1, pi2);
    return 0;
}