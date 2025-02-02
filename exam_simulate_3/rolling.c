#include <stdio.h>
#include <stdlib.h>

int m, n;
int** a;

void roll(int x) {
    int i = 0, j = x;
    while(i < m) {
        if(a[i][j] == 1 && j == n - 1) {
            printf("-1 ");
            return;
        }
        if(a[i][j] == 1 && j + 1 < n && a[i][j + 1] == -1) {
            printf("-1 ");
            return;
        }
        if(a[i][j] == -1 && j == 0) {
            printf("-1 ");
            return;
        }
        if(a[i][j] == -1 && j - 1 >= 0 && a[i][j - 1] == 1) {
            printf("-1 ");
            return;
        }
        int k = a[i][j];
        i += 1;
        j += k;
    }
    printf("%d ", j);
    return;
}

int main() {
    scanf("%d %d", &m, &n);
    a = malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++) {
        a[i] = malloc(n * sizeof(int));
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    for(int i = 0; i < n; i++)
        roll(i);
    return 0;
}