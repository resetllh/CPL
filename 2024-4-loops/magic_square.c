#include <stdio.h>

#define N 1000
int a[N][N] = {0};

int main() {
    int n;
    scanf("%d", &n);
    int r, c;
    for(int i = 1; i <= n * n; i++) {
        if(i == 1) {
            a[0][n / 2] = 1;
            r = 0;
            c = n / 2;
        }
        else {
            int nr = (r + n - 1) % n;
            int nc = (c + 1) % n;
            if(a[nr][nc] == 0) {
                a[nr][nc] = i;
                r = nr;
                c = nc;
            }
            else {
                r = (r + 1) % n;
                a[r][c] = i;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}