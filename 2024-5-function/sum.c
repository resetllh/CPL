#include <stdio.h>

int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    int sum = t;
    int temp = t;
    for(int i = 2; i <= n; i++) {
        temp = temp * 10 + t;
        sum += temp;
    }
    printf("%d", sum);
    return 0;
}