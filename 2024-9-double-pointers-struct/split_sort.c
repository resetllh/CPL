#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_str(const void * p1,const void * p2) {
    return strcmp(*(char**)p1, *(char**)p2);
}

int main() {
    char* s = malloc(1000000);
    char* t = malloc(1000000);
    char** ans = malloc(1000000);
    scanf("%s\n%s", s, t);
    char* para = strtok(s, t);
    int len = 0;
    while(para != NULL) {
        ans[len++] = para;
        para = strtok(NULL, t);
    }
    qsort(ans, len, sizeof(ans[0]), compare_str);
    for(int i = 0; i < len; i++) printf("%s\n", ans[i]);
    return 0;
}