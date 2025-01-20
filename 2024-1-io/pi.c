#include <stdio.h>
#include <math.h>

int main() {
    double pi_1 = 4 * (4 * atan(0.2) - atan(1. / 239));
    double pi_2 = log(pow(640320, 3) + 744) / sqrt(163);
    printf("%.15lf\n%.15lf", pi_1, pi_2);
    return 0;
}