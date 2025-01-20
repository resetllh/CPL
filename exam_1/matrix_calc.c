#include <stdio.h>

int op;
int n;
int a[100][100];
int b[100][100];
long long c[100][100];

void cal() {
    if(op == 1) {
        for(int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                c[i][j] = a[i][j] + b[i][j];
    }
    if(op == 2) {
        for(int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                c[i][j] = a[i][j] - b[i][j];
    }
    if(op == 3) {
        for(int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                long long res = 0;
                for(int k = 0; k < n; k++)
                    res += a[i][k] * b[k][j];
                c[i][j] = res;
            }
    }
    if(op == 4) {
        for(int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                c[i][j] = a[j][i];
    }
}

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%lld ", c[i][j]);
        printf("\n");
    }
}

int main() {
    scanf("%d\n%d", &op, &n);
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    if(op != 4) {
        for(int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &b[i][j]);
    }
    cal();
    print();
    return 0;
}