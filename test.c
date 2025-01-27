#include <stdio.h>
#include <string.h>

int main() {
    char s1[10] = "kjaf";
    char s2[10] = "mfakmf";
    strcat(s2, "\0");
    printf("s1: %s\n", s1); // 输出 s1
    printf("s2: %s\n", s2); // 输出 s2

    return 0;
}