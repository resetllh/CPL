#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a & b);
    printf("%d\n", a | b);
    printf("%d\n", a ^ b);
    printf("%d\n", ~a);
    printf("%d\n", a << b);
    printf("%d\n", a >> b);
    printf("%d\n", (a >> b) & 1);
    int cnt = 0;
    while(a != 0) {
        int last = a & 1;
        if(last == 1) cnt++;
        a /= 2;
    }
    printf("%d\n", cnt);
    return 0;
}