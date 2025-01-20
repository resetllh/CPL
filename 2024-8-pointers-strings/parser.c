#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_charc(char s) {
    return (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z');
}

bool is_valid(char* s) {
    if(strlen(s) == 2 && is_charc(*(s + 1)) && *s == '-') return true;
    else return false;
}

int main() {
    char* rule = malloc(130);
    char* s = malloc(1024);
    char* t = malloc(2048);
    char* name = malloc(1024);

    scanf("%s", rule);
    scanf("%s", name);
    bool terminal = false;
    bool need_parm = false;
    int len_r = strlen(rule);
    int len = 0;
    while(scanf("%s", s) != EOF) {
        if(need_parm == false) {
            if(!is_valid(s)) continue;
            char c = *(s + 1);
            int i;
            for(i = 0; i < len_r; i++)
                if(*(rule + i) == c) break;
            if(i == len_r) {
                printf("%s: invalid option -- '%c'", name, c);
                terminal = true;
                break;
            }
            *(t + len++) = '\n';
            *(t + len++) = c;
            if(i + 1 < len_r && *(rule + i + 1) == ':') {
                need_parm = true;
                *(t + len++) = '=';
            }
        }
        else {
            strcat(t, s);
            len = strlen(t);
            need_parm = false;
        }
    }
    if(!terminal) {
        if(need_parm) printf("%s: option requires an argument -- '%c'", name, t[len - 2]);
        else {
            *(t + len++) = '\0';
            printf("%s%s", name, t);
        }
    }
    return 0;
}