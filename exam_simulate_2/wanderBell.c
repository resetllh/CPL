#include <stdio.h>


int R, C;
char map[3000][3000];
int count_row[3000] = {0};
int count_col[3000] = {0};

typedef struct pos
{
    int x;
    int y;
} pos;
pos p[9000000];
int l = 0;

int check(int i, int j) {
    int s1 = 0, s2 = 0;
    if(map[i][j] == 'L') s2 = -1;
    if(map[i][j] == 'R') s2 = 1;
    if(map[i][j] == 'U') s1 = -1;
    if(map[i][j] == 'D') s1 = 1;

    do {
        i += s1;
        j += s2;
    } while(i >= 0 && i < R && j >= 0 && j < C && map[i][j] == '.');

    if(i >= 0 && i < R && j >= 0 && j < C)
        return 0;
    else
        return 1;
}

int main() {
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++) {
        char s[3000];
        scanf("%s", s);
        for(int j = 0; j < C; j++) {
            map[i][j] = s[j];
            if(s[j] != '.') {
                count_row[i]++;
                count_col[j]++;
                p[l].x = i;
                p[l].y = j;
                l++;
            }
        }
    }
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            if(count_row[i] == 1 && count_col[j] == 1 && map[i][j] != '.') {
                printf("-1");
                return 0;
            }
    int ans = 0;
    for(int i = 0; i < l; i++) {
        int x = p[i].x;
        int y = p[i].y;
        ans += check(x, y);
    }
    printf("%d", ans);
    return 0;
}