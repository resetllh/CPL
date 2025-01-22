#include <stdio.h>

int width[30];
int left[30];
int right[30];

char a[30][1000000];

void paint(int n, int x, int y) {
    if(n == 0)
        return;
    if(n == 1) {
        a[x][y] = '\\';
        return;
    }
    int y1 = left[n] - 1 + y;
    int y2 = right[n] - 1 + y;
    a[x + n - 1][y1] = '\\';
    a[x + n - 1][y2] = '/';
    for(int i = y1 + 1; i < y2; i++)
        a[x + n - 1][i] = '_';
    paint(n - 1, x, y);
    x = x + 1;
    y = y + width[n - 1] + 1;
    paint(n - 2, x, y);
}

void display(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < width[n]; j++)
            if(a[i][j] == '\0') printf(" ");
            else printf("%c", a[i][j]);
        printf("\n");
    }
}

int main() {
    width[1] = 1;
    width[2] = 3;
    left[1] = 1;
    left[2] = 2;
    right[2] = 3;
    right[3] = 5;
    for(int i = 3; i < 30; i++) {
        width[i] = width[i - 1] + width[i - 2] + 1;
        left[i] = right[i - 1];
        if(i > 3) right[i] = left[i - 2] + 1 + width[i - 1];
    }

    int n;
    scanf("%d", &n);
    paint(n, 0, 0);
    display(n);
}