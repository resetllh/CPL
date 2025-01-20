#include <stdio.h>
char s[3000];

int main() {
    int n;
    scanf("%d %s", &n, s);
    for(int i = 0; i < n; i++) {
        if(s[i] != '?') printf("%c", s[i]);
        else printf("%c", s[n - 1 -i]);
    }
    return 0;
}