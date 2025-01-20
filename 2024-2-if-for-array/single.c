#include <stdio.h>
int a[10000000];

int main() {
    int n, ans=0;
    scanf("%d", &n);
    for(int i = 0; i < 2 * n - 1; i++) {
        scanf("%d", &a[i]);
        ans ^= a[i];
    }
    printf("%d", ans);
    return 0;
}