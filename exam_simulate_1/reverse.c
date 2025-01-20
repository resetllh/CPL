#include <stdio.h>

char s[1000000];

int main() {
    int len;
    scanf("%d", &len);
    scanf("%s", s);
    for(int i = len - 1; i >= 0; i--) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            printf("%c", s[i] + 'A' - 'a');
        }
        else if(s[i] >= 'A' && s[i] <= 'Z') {
            printf("%c", s[i] - 'A' + 'a');
        }
        else {
            printf("%c", s[i]);
        }
    }
    return 0;
}