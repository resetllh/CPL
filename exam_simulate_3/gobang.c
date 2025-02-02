#include <stdio.h>
#include <stdbool.h>

char board[20][20];

int has_down(int i, int j, char c) {
    int cnt = -1;
    if(i + 4 < 20) {
        int cnt_c = 0;
        int cnt_e = 0;
        for(int k = 0; k < 5; k++)
            if(board[i + k][j] == c)
                cnt_c++;
            else if(board[i + k][j] == '_')
                cnt_e++;

        if(cnt_c == 4 && cnt_e == 1) {
            for(int k = 0; k < 5; k++)
                if(board[i + k][j] == '_')
                    cnt = 20 * (i + k) + j;
        }
    }
    return cnt;
}

int has_right(int i, int j, char c) {
    int cnt = -1;
    if(j + 4 < 20) {
        int cnt_c = 0;
        int cnt_e = 0;
        for(int k = 0; k < 5; k++)
            if(board[i][j + k] == c)
                cnt_c++;
            else if(board[i][j + k] == '_')
                cnt_e++;

        if(cnt_c == 4 && cnt_e == 1) {
            for(int k = 0; k < 5; k++)
                if(board[i][j + k] == '_')
                    cnt = 20 * i + j + k;
        }
    }
    return cnt;
}

int has_tilt_1(int i, int j, char c) {
    int cnt = -1;
    if(i + 4 < 20 && j + 4 < 20) {
        int cnt_c = 0;
        int cnt_e = 0;
        for(int k = 0; k < 5; k++)
            if(board[i + k][j + k] == c)
                cnt_c++;
            else if(board[i + k][j + k] == '_')
                cnt_e++;

        if(cnt_c == 4 && cnt_e == 1) {
            for(int k = 0; k < 5; k++)
                if(board[i + k][j + k] == '_')
                    cnt = 20 * (i + k) + j + k;
        }
    }
    return cnt;
}

int has_tilt_2(int i, int j, char c) {
    int cnt = -1;
    if(i + 4 < 20 && j - 4 >= 0) {
        int cnt_c = 0;
        int cnt_e = 0;
        for(int k = 0; k < 5; k++)
            if(board[i + k][j - k] == c)
                cnt_c++;
            else if(board[i + k][j - k] == '_')
                cnt_e++;

        if(cnt_c == 4 && cnt_e == 1) {
            for(int k = 0; k < 5; k++)
                if(board[i + k][j - k] == '_')
                    cnt = 20 * (i + k) + j - k;
        }
    }
    return cnt;
}

void game() {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            int r = has_right(i, j, '*');
            int d = has_down(i, j, '*');
            int t1 = has_tilt_1(i, j, '*');
            int t2 = has_tilt_2(i, j, '*');
            if(r != -1 || d != -1 || t1 != -1 || t2 != -1) {
                printf("Lose\n");
                return;
            }
        }
    }
    
    bool flag = false;
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            int r = has_right(i, j, '#');
            int d = has_down(i, j, '#');
            int t1 = has_tilt_1(i, j, '#');
            int t2 = has_tilt_2(i, j, '#');

            if(r != -1 || d != -1 || t1 != -1 || t2 != -1) {
                int n;
                if(r != -1)
                    n = r;
                else if(d != -1)
                    n = d;
                else if(t1 != -1)
                    n = t1;
                else
                    n = t2;

                int x = n / 20;
                int y = n % 20;
                board[x][y] = '*';
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    if(flag == false) {
        printf("Not Sure\n");
        return;
    }

    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            int r = has_right(i, j, '#');
            int d = has_down(i, j, '#');
            int t1 = has_tilt_1(i, j, '#');
            int t2 = has_tilt_2(i, j, '#');

            if(r != -1 || d != -1 || t1 != -1 || t2 != -1) {
                printf("Win\n");
                return;
            }
        }
    }
    printf("Not Sure\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while(T-- > 0) {
        for(int i = 0; i < 20; i++) {
            char s[25];
            scanf("%s", s);
            for(int j = 0; j < 20; j++)
                board[i][j] = s[j];
        }
        game();
    }
    return 0;
}