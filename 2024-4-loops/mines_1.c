#include <stdio.h>
#include <stdbool.h>
char a[100][100];

bool is_legal(int i, int j, int n) {
    if(i >= 0 && i <n && j >= 0 && j < n) return true;
    else return false;
}

int get_count(int i, int j, int n) {
    int cnt = 0;
    if(is_legal(i, j - 1, n) && a[i][j - 1] == '*') cnt++;
    if(is_legal(i, j + 1, n) && a[i][j + 1] == '*') cnt++;
    if(is_legal(i - 1, j, n) && a[i - 1][j] == '*') cnt++;
    if(is_legal(i + 1, j, n) && a[i + 1][j] == '*') cnt++;
    if(is_legal(i - 1, j - 1, n) && a[i - 1][j - 1] == '*') cnt++;
    if(is_legal(i + 1, j - 1, n) && a[i + 1][j - 1] == '*') cnt++;
    if(is_legal(i - 1, j + 1, n) && a[i - 1][j + 1] == '*') cnt++;
    if(is_legal(i + 1, j + 1, n) && a[i + 1][j + 1] == '*') cnt++;
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%c", &a[i][j]);
        }
        getchar();
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == '*') printf("*");
            else {
                int cnt = get_count(i, j, n);
                printf("%d", cnt);
            }
        }
        printf("\n");
    }
    return 0;
}