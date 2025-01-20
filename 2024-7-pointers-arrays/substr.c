#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char* s = malloc(100005);
    char* t = malloc(100005);
    scanf("%s\n%s", s, t);
    int ls = strlen(s);
    int lt = strlen(t);
    for(int i = 0; i < ls; i++) {
        bool flag = true;
        for(int j = 0; j < lt; j++) {
            if(i + j >= ls || *(s + i + j) != *(t + j)) {
                flag = false;
                break;
            }
        }
        if(flag) printf("%d ", i);
    }
    free(s);
    free(t);
    return 0;
}