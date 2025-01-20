#include <stdio.h>
#include <stdbool.h>

char a[100][100];
bool is_visit[100][100] = {0};
int n, m, x, y;

void print_path() {
    int i = x, j = y;
    while(a[i][j] == '#' && is_visit[i][j] == false) {
        printf("%d %d\n", i, j);
        is_visit[i][j] = true;
        if(i + 1 <= n && a[i + 1][j] == '#' && is_visit[i + 1][j] == false) {
            i = i + 1;
            continue;
        }
        if(i - 1 >= 1 && a[i - 1][j] == '#' && is_visit[i - 1][j] == false) {
            i = i - 1;
            continue;
        }
        if(j + 1 <= m && a[i][j + 1] == '#' && is_visit[i][j + 1] == false) {
            j = j + 1;
            continue;
        }
        if(j - 1 >= 1 && a[i][j - 1] == '#' && is_visit[i][j - 1] == false) {
            j = j - 1;
            continue;
        }
    }
}

int main() {
    int cnt = 0;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for(int i = 1; i <= n; i++) {
        char s[100];
        scanf("%s", s);
        for(int j = 1; j <= m; j++) {
            a[i][j] = s[j - 1];
            if(s[j - 1] == '#') cnt++;
        }
    }
    printf("%d\n", cnt);
    print_path();
    return 0;
}