#include <stdio.h>
#include <string.h>
char s[1005];
char t[1005];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    while(n--) {
        int len = strlen(s);
        for(int i = 0; i < len; i++) {
            int a = 0;
            int b = 0;
            int empty = 0;
            for(int j = i - 3; j <= i + 3; j++) {
                if(j < 0 || j >= len || j == i) continue;
                if(s[j] == 'A') a++;
                else if(s[j] == 'B') b++;
                else empty++;
            }
            if(s[i] == '.') {
                if(a == 0 && b >= 2 && b <= 4) {
                    t[i] = 'B';
                }
                else if(b == 0 && a >= 2 && a <= 4) {
                    t[i] = 'A';
                }
                else t[i] = '.';
            }
            else {
                if(s[i] == 'A') {
                    if(b != 0 || a >= 5 || a <= 1) {
                        t[i] = '.';
                    }
                    else t[i] = 'A';
                }
                else {
                    if(a != 0 || b >= 5 || b <= 1) {
                        t[i] = '.';
                    }
                    else t[i] = 'B';
                }
            }
        }
        t[len] = '\0';
        strncpy(s, t, len);
    }
    printf("%s", s);
    return 0;
}