#include <stdio.h>
#include <stdbool.h>

int R, C;
char s[200][200];

bool is_square(int i, int j, int len) {
    if(j + len < C && j - len + 1 >= 0 
    && i >= 0 && i + 2 * len - 1 < R) {
        for(int k = 0; k < len; k++) 
            if(s[i + k][j - k] != '/') 
                return false;
        for(int k = 0; k < len; k++) 
            if(s[i + k][j + 1 + k] != '\\') 
                return false;
        for(int k = 0; k < len; k++) 
            if(s[i + len + k][j - len + 1 + k] != '\\') 
                return false;
        for(int k = 0; k < len; k++) 
            if(s[i + len + k][j + len - k] != '/') 
                return false;
    }
    else return false;
    return true;
}

int main() {
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++) {
        char str[200];
        scanf("%s", str);
        for(int j = 0; j < C; j++) s[i][j] = str[j];
    }
    int cnt = 0;
    int l = R > C ? R: C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            for(int k = 1; k <= l; k++)
                if(is_square(i, j, k)) 
                    cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}