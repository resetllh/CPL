#include <stdio.h>
#include <string.h>
int a, b, c;
int x1, x2, y_1, y2;

void rotate(char s) {
    int l1 = x2 - x1;
    int l2 = y2 - y_1;
    int l3 = a + b + c - l1 - l2;
    switch (s)
    {
    case 'W':
        x2 = x1;
        x1 = x1 - l3;
        break;
    case 'S':
        x1 = x2;
        x2 = x2 + l3;
        break;
    case 'A':
        y2 = y_1;
        y_1 = y_1 - l3;
        break;
    case 'D':
        y_1 = y2;
        y2 = y2 + l3;
        break;
    }
}

int main() {
    scanf("%d %d %d", &a, &b, &c);
    char s[2000];
    scanf("%s", s);
    int len = strlen(s);
    x1 = 0, x2 = a, y_1 = 0, y2 = b;
    for(int i = 0; i < len; i++)
        rotate(s[i]);
    printf("%d %d %d %d", x1, x2, y_1, y2);
    return 0;
}