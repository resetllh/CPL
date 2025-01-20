#include <stdio.h>

int cab(int a, int b) {
    if(a <= 1 || b <= 1 || a == b) return 1;
    else return cab(a - 1, b - 1) + cab(a - 1, b);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", cab(a, b));
    return 0;
}