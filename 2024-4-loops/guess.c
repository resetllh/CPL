#include <stdio.h>
#include <stdlib.h>

int main() {
    char res[10];

    long long unsigned int l = 0;
    long long unsigned int r = (long long unsigned int) 2 << 32;
    r -= 1;
    long long unsigned int guess = (l + r) / 2;

    while(1) {
        printf("%llu\n", guess);
        fflush(stdout);
        scanf("%s", res);

        switch (res[0]) {
            case 'G': {
                r = guess - 1;
                guess = (l + r) / 2;
                break;
            }
            case 'L': {
                l = guess + 1;
                guess = (l + r) / 2;
                break;
            }
            case 'E': return 0;
            case 'O': return 0;
        }
    }
}