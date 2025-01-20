#include <stdio.h>
char s[1000000];
int tag[1000000];

int main() {
    int n;
    scanf("%d %s", &n, s);
    int i = 0, j = 0;
    for(int k = 0; k < n ; k++) {
        if(s[k] != '?') printf("%c", s[k]);
        else if(s[n - 1 - k] != '?') printf("%c", s[n - 1 -k]);
        else if(tag[k] == 0) {
            tag[k] = 10 * i + j + 1;
            tag[n - 1 - k] = 10 * j + i + 1;
            i = tag[k] / 10;
            j = tag[k] % 10;
            printf("%.2d", tag[k] - 1);
        }
        else {
            printf("%.2d", tag[k] - 1);
        }
    }
    return 0;
}