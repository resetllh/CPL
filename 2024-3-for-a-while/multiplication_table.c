#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%dx%d=%d ", j, i, j * i);
        }
        if(i != n) {
            printf("\n");
        }
    }
    return 0;
}