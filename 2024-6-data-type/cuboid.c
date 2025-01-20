#include <stdio.h>

void draw_cube(int a, int b, int c) {
    int row = 2 * b + 2 * c + 1;
    int col = 2 * a + 2 * b + 1;
    char s[row][col];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++)
            s[i][j] = '*';
    }

    for(int j = 0; j < col; j++) {
        if(j < 2 * b) s[0][j] = '*';
        else if(j % 2 == 0) s[0][j] = '+';
        else s[0][j] = '-';
    }
    for(int i = 0; i < row; i++) {
        if(i < 2 * b) s[row - 1 - i][col - 1] = '*';
        else if(i % 2 == 0) s[row - 1 - i][col - 1] = '+';
        else s[row - 1 - i][col - 1] = '|';
    }
    
    for(int k = 1; k <= 2 * b ; k++) {
        for(int j = 0; j < col - k; j++) {
            if(s[k - 1][j + 1] == '+')
                s[k][j] = '/';
            else if(s[k - 1][j + 1] == '/')
                s[k][j] = '+';
            else if(s[k - 1][j + 1] == '-')
                s[k][j] = ' ';
            else if(s[k - 1][j + 1] == ' ')
                s[k][j] = '-';   
        }
        for(int i = row - 1; i >= k; i--) {
            if(s[i - 1][col - k] == '+')
                s[i][col - k - 1] = '/';
            else if(s[i - 1][col - k] == '|')
                s[i][col - k - 1] = ' ';
            else if(s[i - 1][col - k] == '/')
                s[i][col - k - 1] = '+';
            else if(s[i - 1][col - k] == ' ')
                s[i][col - k - 1] = '|';
        }
    }

    for(int i = 2 * b + 1; i < row; i++)
        for(int j = 0; j < 2 * a; j++) {
            if(s[i - 1][j] == '+')
                s[i][j] = '|';
            else if(s[i - 1][j] == '-')
                s[i][j] = ' ';
            else if(s[i - 1][j] == '|')
                s[i][j] = '+';
            else if(s[i - 1][j] == ' ')
                s[i][j] = '-';
        }   

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++)
            printf("%c", s[i][j] == '*' ? ' ': s[i][j]);
        printf("\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        draw_cube(a, b, c);
    }
    return 0;
}