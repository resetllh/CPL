#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char* s = malloc(1005);
    char* t = malloc(1005);
    scanf("%s", s);
    int len = strlen(s);
    int T = 0;
    while(T < n) {
        for(int i = 0; i < len; i++) {
            int count_a = 0;
            int count_b = 0;
            for(int j = -3; j <= 3; j++) {
                if(i + j >= 0 && i + j < len && j != 0) {
                    if(*(s + i + j) == 'A') count_a++;
                    else if(*(s + i + j) == 'B') count_b++;
                }
            }
            if( *(s + i) == '.') {
                if(count_a >= 2 && count_a <= 4 && count_b == 0) *(t + i) = 'A';
                else if(count_b >= 2 && count_b <= 4 && count_a == 0) *(t + i) = 'B';
                else *(t + i) = '.';
            }
            else if(*(s + i) == 'A') {
                if(count_b > 0 || count_a >=5 || count_a <= 1) *(t + i) = '.';
                else *(t + i) = 'A';
            }
            else if(*(s + i) == 'B') {
                if(count_a > 0 || count_b >=5 || count_b <= 1) *(t + i) = '.';
                else *(t + i) = 'B';
            }
        }
        for(int i = 0; i < len; i++) *(s + i) = *(t + i);
        T++;
    }
    printf("%s", s);
    free(s);
    free(t);
    return 0;
}