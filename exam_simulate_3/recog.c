#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const char _0[17][9 + 1] = { // +1 for '\0'
  "..#####.",
  ".######.",
  "##....##",
  "##....##",
  "##.....#",
  "##.....#",
  "##.....#",
  "##.....#",
  "##.....#",
  "##.....#",
  "##.....#",
  "##.....#",
  "##.....#",
  "##....##",
  "##....##",
  ".######.",
  "..####.."
};

const char _1[17][9 + 1] = {
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
  "##",
};

const char _2[17][9 + 1] = {
  "..#####..",
  ".#######.",
  "##....##.",
  ".......##",
  "......##.",
  "......##.",
  "......##.",
  ".....##..",
  "....###..",
  "...###...",
  "...##....",
  "..###....",
  ".###.....",
  ".##......",
  "###......",
  "########.",
  "########."
};

const char _3[17][9 + 1] = {
  "########",
  "########",
  ".....###",
  "....###.",
  "...###..",
  "..###...",
  "..#####.",
  "..######",
  "......##",
  "......##",
  "......##",
  "......##",
  "##....##",
  "##....##",
  "###...##",
  ".######.",
  "..####.."
};

const char _4[17][9 + 1] = {
  ".....##..",
  "....###..",
  "....###..",
  "...####..",
  "...####..",
  "...####..",
  "..#####..",
  "..##.##..",
  ".###.##..",
  ".##..##..",
  ".##..##..",
  "##...##..",
  "#########",
  "#########",
  ".....##..",
  ".....##..",
  ".....##.."
};

const char _5[17][9 + 1] = {
  "########.",
  "########.",
  "##.......",
  "##.......",
  "##.......",
  "##.......",
  "#######..",
  "########.",
  "......###",
  ".......##",
  ".......##",
  ".......##",
  ".......##",
  "##.....##",
  ".##...###",
  ".#######.",
  "..#####.."
};

const char _6[17][9 + 1] = {
  ".....#...",
  "....##...",
  "...##....",
  "..###....",
  "..##.....",
  ".##......",
  ".##......",
  ".#####...",
  "#######..",
  "###...##.",
  "##....##.",
  "##.....##",
  "##.....##",
  "##.....##",
  "###...##.",
  ".#######.",
  "..####..."
};

const char _7[17][9 + 1] = {
  "#########",
  "#########",
  ".......#.",
  "......##.",
  "......##.",
  ".....##..",
  ".....##..",
  ".....#...",
  "....##...",
  "....##...",
  "....##...",
  "...##....",
  "...##....",
  "...##....",
  "...##....",
  "...##....",
  "...##....",
};

const char _8[17][9 + 1] = {
  "..#####..",
  ".##...##.",
  "##.....#.",
  "##.....#.",
  "##.....#.",
  "##....##.",
  ".##..###.",
  "..#####..",
  ".#######.",
  "##....##.",
  "##.....##",
  "##.....##",
  "##.....##",
  "##.....##",
  "###..###.",
  ".######..",
  "...###..."
};

const char _9[17][9 + 1] = {
  ".######..",
  ".##..###.",
  "##....##.",
  "##.....##",
  "##.....##",
  "##.....##",
  "##....##.",
  ".#######.",
  "..######.",
  ".....###.",
  ".....##..",
  "....###..",
  "....##...",
  "...##....",
  "..###....",
  ".###.....",
  "........."
};

struct Number {
  const char (*p)[10]; 
  int n;
  int m; 
};

struct Number numbers[] = {
  {_0, 17, 8},
  {_1, 17, 2},
  {_2, 17, 9},
  {_3, 17, 8},
  {_4, 17, 9},
  {_5, 17, 9},
  {_6, 17, 9},
  {_7, 17, 9},
  {_8, 17, 9},
  {_9, 17, 9},
};

char s[50][101];

bool check_row(int idx) {
    for(int j = 0; j < 100; j++)
        if(s[idx][j] == '#')
            return true;
    return false;
}

bool check_col(int idx) {
    for(int j = 0; j < 50; j++)
        if(s[j][idx] == '#')
            return true;
    return false;
}

int match(int l, int r, int up, int lw) {
    int n1 = lw - up + 1;
    int m1 = r - l + 1;
    for(int i = 0; i <= 9; i++) {
        if(n1 != numbers[i].n || m1 != numbers[i].m)
            continue;
        bool tag = true;
        for(int j = 0; j < n1; j++)
            for(int k = 0; k < m1; k++)
                if((numbers[i].p)[j][k] != s[up + j][l + k]) {
                    tag = false;
                    break;
                }
        if(tag == true)
            return i;

    }
    return -1;
}

int main() {
    for(int i = 0; i < 50; i++)
        scanf("%s", s[i]);

    int up = 0, lw = 49;
    while(!check_row(up))
        up++;
    while(!check_row(lw))
        lw--;

    printf("%d %d\n", up, lw);

    int ans[10];
    int idx = 0;
    int l = 99, r = 99;

    for(int cnt = 0; cnt < 5; cnt++) {
        while(!check_col(r))
            r--;
        l = r;
        while(check_col(l))
            l--;
        l++;
        int temp = match(l, r, up, lw);
        if(temp != -1)
            ans[idx++] = temp;
        r = l - 1;
    }

    for(int k = idx - 1; k >= 0; k--)
        printf("%d ", ans[k]);

    return 0;
}