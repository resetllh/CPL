#include <stdio.h>
#include <stdbool.h>

typedef struct pos {
    int i;
    int j;
    int k;
} pos;

pos unknow;
int n;
char map[600][600][600];
char s[1000000000];

bool is_num(int i, int j, int k) {
    return map[i][j][k] >= '0' && map[i][j][k] <= '9';
}

int get_count(int i, int j, int k, int inc) {
    int cnt = 0;
    int has = 0;
    if(i + 1 < n && !is_num(i + 1, j, k)) {
        cnt ++;
        if(map[i + 1][j][k] == '?')
            has = 1;
    }
    if(i >= 1 && !is_num(i - 1, j, k)) {
        cnt ++;
        if(map[i - 1][j][k] == '?')
            has = 1;
    }
    if(j + 1 < n && !is_num(i, j + 1, k)) {
        cnt ++;
        if(map[i][j + 1][k] == '?')
            has = 1;
    }
    if(j >= 1 && !is_num(i, j - 1, k)) {
        cnt ++;
        if(map[i][j - 1][k] == '?')
            has = 1;
    }
    if(k + 1 < n && !is_num(i, j, k + 1)) {
        cnt ++;
        if(map[i][j][k + 1] == '?')
            has = 1;
    }
    if(k >= 1 && !is_num(i, j, k - 1)) {
        cnt ++;
        if(map[i][j][k - 1] == '?')
            has = 1;
    }
    if(inc == 1) return cnt;
    else return cnt - has;
}

bool complete(int inc) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++) {
                if(is_num(i, j, k)) {
                    int cnt = get_count(i, j, k, inc);
                    if(cnt + '0' != map[i][j][k]) {
                        return false;
                    }
                }
            }
    return true;
}

void check() {
    if(complete(0)) {
        printf("valid\n");
        printf("%d", get_count(unknow.i, unknow.j, unknow.k, 0));
        return;
    }
    if(complete(1)) {
        printf("valid\n");
        printf("*");
        return;
    }
    printf("invalid\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++) {
                if(is_num(i, j, k)) {
                    int cnt = get_count(i, j, k, 1);
                    if(cnt + '0' != map[i][j][k]) {
                        printf("%d %d %d\n", i + 1, j + 1, k + 1);
                    }
                }
            }
}

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++) {
                map[i][j][k] = s[cnt++];
                if(map[i][j][k] == '?') {
                    unknow.i = i;
                    unknow.j = j;
                    unknow.k = k;
                }
            }
    check();
    return 0;
}