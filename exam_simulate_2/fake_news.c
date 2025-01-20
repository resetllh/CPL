#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_big_letter(char c) {
    return 'A' <= c && c <= 'Z';
}

int main() {
    char s[2000];
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(is_big_letter(s[i]) && i != 0) {
            printf(" %c", s[i] - 'A' + 'a');
        }
        else {
            printf("%c", s[i]);
        }
    }
    return 0;
}