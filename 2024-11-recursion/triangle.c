#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char ** a;

void init(int n) {
    int h = pow(2, n);
    int w = 2 * h;
    a = calloc(h, sizeof(char*));
    for(int i = 0; i < h; i++) a[i] = calloc(w, sizeof(char));
}

void paint(int n, int x, int y) {
    if(n == 1) {
        a[x][y] = '/';
        a[x][y + 1] = '\\';
        a[x + 1][y - 1] = '/';
        a[x + 1][y + 2] = '\\';
        a[x + 1][y] = '_';
        a[x + 1][y + 1] = '_';
    }
    else {
        int l = pow(2, n);
        paint(n - 1, x, y);
        paint(n - 1, x + l / 2, y - l / 2);
        paint(n - 1, x + l / 2, y + l / 2);
    }
}

void display(int n) {
    int h = pow(2, n);
    int w = 2 * h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(a[i][j] == '\0') printf(" ");
            else printf("%c", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    init(n);
    paint(n, 0, pow(2, n) - 1);
    display(n);
    return 0;
}