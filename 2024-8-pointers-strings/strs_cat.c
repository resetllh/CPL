#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char* s = malloc(1005);
    char* t = malloc(1005);
    int T;
    scanf("%d", &T);
    int cnt = 0;
    while(cnt < T) {
        scanf("%s %s", s, t);
        int ls = strlen(s);
        int lt = strlen(t);
        int i;
        for(i = 0; i < ls; i++) {
            int flag = 1;
            for(int j = i; j < ls; j++) {
                if(j - i < lt && *(s + j) == *(t + j - i))
                    continue;
                else {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) break;
        }
        for(int j = 0; j < i; j++) printf("%c", *(s + j));
        for(int j = 0; j < lt; j++) printf("%c", *(t + j));
        printf("\n");
        cnt++;
    }
    free(s);
    free(t);
    return 0;
}