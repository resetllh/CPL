#include <stdio.h>
int a[200000];
int b[200000];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
        if(i == 0) {
            b[i] = a[i];
        }
        else {
            b[i] = b[i-1] + a[i];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n ; i++) {
        ans = ans > (i - b[i-1]) ? ans: i - b[i - 1];
    }
    printf("%d", ans);
    return 0;
}