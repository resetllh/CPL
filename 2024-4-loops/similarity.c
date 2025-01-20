#include <stdio.h>
#define M 100
#define N 100
int a[M][N];

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int cnt = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int value;
            scanf("%d", &value);
            if(value == a[i][j]) cnt++;
        }
    }
    printf("%.2f", 100.f * cnt / (m * n));
    return 0;
}