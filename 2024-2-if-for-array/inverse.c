#include <stdio.h>
char s[10000005];

int main() {
    int n, k;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++) {
        scanf("%c", &s[i]);
    }
    getchar();
    scanf("%d", &k);
    for(int i = k - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
    for(int i = n - 1; i >= k; i--) {
        printf("%c", s[i]);
    }
    return 0;
}