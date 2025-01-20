#include <stdio.h>
#include <stdlib.h>

char to_lower(char a) {
    if(a >= 'A' && a <= 'Z') return a - 'A' + 'a';
    else return a;
}

char to_higher(char a) {
    if(a >= 'a' && a <= 'z') return a + 'A' - 'a';
    else return a;
}

int main() {
    char* s = malloc(4096);
    while(scanf("%s", s) != EOF) {
        printf("%c", to_higher(*s));
        char* p = s + 1;
        while(*p != '\0') {
            printf("%c", to_lower(*p));
            p++;
        }
        printf(" ");
    }
    free(s);
    return 0;
}