#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int time = 0, max = n;
    while(n != 1) {
        if(n % 2 == 0) {
            n /= 2;
            time += 1;
        }
        else {
            n = 3 * n + 1;
            time += 1;
            max = max > n ? max: n;
        }
    }
    printf("%d %d", time, max);
    return 0;
}