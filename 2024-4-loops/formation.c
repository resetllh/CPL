#include <stdio.h>
int a[2005][2005] = {0};

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for(int j = 1; j <= n; j++) {
        scanf("%1d", &a[1][j]);
    }
    for(int i = 2; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            int x1 = a[i - 1][j - 1];
            int x2 = a[i - 1][j];
            int x3 = a[i - 1][j + 1];
            if(x1 + x2 + x3 == 2 ||
            (x1 == 0 && x2 == 1 && x3 == 0) ||
            (x1 == 0 && x2 == 0 && x3 == 1)) {
                a[i][j] = 1;
            }
        }
    }
    for(int i = 2; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}