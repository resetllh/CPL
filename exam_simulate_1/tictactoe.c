#include <stdio.h>
#include <stdbool.h>

int a[20][20] = {0};
int n;
int t;
int x;

bool check(int i, int j) {
    bool flag = false;
    if(i + x - 1 < n) {
        int and;
        for(int k = 0; k < x; k++) {
            if(k == 0) and = a[i][j];
            else and &= a[i + k][j];
        }
        if(and != 0) return true;
    }
    if(j + x - 1 < n) {
        int and;
        for(int k = 0; k < x; k++) {
            if(k == 0) and = a[i][j];
            else and &= a[i][j + k];
        }
        if(and != 0) return true;
    }
    if(i + x - 1 < n && j + x - 1 < n) {
        int and;
        for(int k = 0; k < x; k++) {
            if(k == 0) and = a[i][j];
            else and &= a[i + k][j + k];
        }
        if(and != 0) return true;
    }
    if(i + x - 1 < n && j - x + 1 >= 0) {
        int and;
        for(int k = 0; k < x; k++) {
            if(k == 0) and = a[i][j];
            else and &= a[i + k][j - k];
        }
        if(and != 0) return true;
    }
    return false;
}

int main() {
    scanf("%d %d", &t, &x);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        int win[10] = {0};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] != 0 && check(i, j)) {
                    win[a[i][j]] = 1;
                }
            }
        }
        if(win[1] + win[2] + win[4] != 1) printf("draw\n");
        else {
            if(win[1] == 1) printf("1\n");
            else if(win[2] == 1) printf("2\n");
            else printf("4\n");
        }
    }
    return 0;
}