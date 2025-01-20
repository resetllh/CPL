#include <stdio.h>

int solutions(int n) {
    if(n == 1 || n == 2) return n;
    else return solutions(n - 1) + solutions(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", solutions(n));
    return 0;
}