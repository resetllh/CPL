#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char s[1005];
int t[30] = {0};
int T[30] = {0};
char table[1005][100];

int main() {
    int n, len;
    scanf("%d", &n);
    scanf("%s", s);
    len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            int id = s[i] - 'a';
            t[id]++;
        }
        else {
            int id = s[i] - 'A';
            T[id]++;
        }
    }
    memset(table, '0', sizeof(table));

    int max = 0;
    for(int i = 0; i < 30; i++) {
        if(t[i] > max) max = t[i];
        if(T[i] > max) max = T[i];
    }
    int row = max + 2;

    int col = 0;
    for(int i = 0; i < 30; i++) {
        bool flag = false;
        if(t[i] != 0) {
            table[row - 1][col] = 'a' + i;
            table[row - 2][col] = '-';
            for(int j = 0; j < t[i]; j++) {
                table[row - 3 - j][col] = '=';
            }
            col++;
            flag = true;
        }
        if(T[i] != 0) {
            table[row - 1][col] = 'A' + i;
            table[row - 2][col] = '-';
            for(int j = 0; j < T[i]; j++) {
                table[row - 3 - j][col] = '=';
            }
            col++;
            flag = true;
        }
        if(flag) {
            table[row - 1][col] = ' ';
            table[row - 2][col] = '-';
            col++;
        }
    }
    col--;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(table[i][j] == '0') {
                printf(" ");
            }
            else {
                printf("%c", table[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}