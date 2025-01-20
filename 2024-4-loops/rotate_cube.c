#include <stdio.h>

int a[6][100][100];
int b[6][100][100];
int n;
int x[4];
int y[4];

void display() {
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++)
                printf("%d ", b[i][j][k]);
            printf("\n");
        }
}

void rotate(int m) {
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                b[i][j][k] = a[i][j][k];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            b[m][i][j] = a[m][n - 1 - j][i];
        }
    display();
}

void rotate_line() {
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                b[i][j][k] = a[i][j][k];
    for(int j = 0; j < n; j++)
            b[x[0]][y[0]][j] = a[x[3]][y[3]][j];
    for(int i = 1; i < 4; i++) {
        for(int j = 0; j < n; j++)
            b[x[i]][y[i]][j] = a[x[i - 1]][y[i - 1]][j];
    }
    display();
}

int main() {
    char s[20];
    scanf("%s", s);
    scanf("%d", &n);
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                scanf("%d", &a[i][j][k]);
    if(s[0] == 'r') {
        int m;
        scanf("%d", &m);
        rotate(m);
    }
    else {
        for(int i = 0; i < 4; i++)
            scanf("%d %d", &x[i], &y[i]);
        rotate_line();
    }
}