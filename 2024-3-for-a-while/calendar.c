#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    if(n != 1) n = n - 2;
    else n = 6;
    int day = 1;
    for(int i = 0; i < n + m; i++) {
        if(i < n) {
            printf("  ");
        }
        else {
            printf("%2d", day);
            day += 1;
        }
        if(i != n + m - 1) {
            if((i + 1) % 7 != 0) {
                printf("  ");
            }
            else {
                printf("\n");
            }
        }
    }
    return 0;
}