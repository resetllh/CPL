#include <stdio.h>

int main() {
    char name[20];
    int pre;
    double frac, factor;
    char unit;
    scanf("%s %d %lf %lf %c", name, &pre, &frac, &factor, &unit);
    
    char N[3] = {name[0], name[1], '\0'};
    int p = pre;
    double sciEexp = pre + frac;
    double conv = sciEexp * factor;
    char new_unit = unit < 'a' ? unit : unit - ('a' - 'A');
    printf("%s: %d (%.5lf) | %.5E %.5lf %c", N, p, frac, sciEexp, conv, new_unit);
    return 0;
}