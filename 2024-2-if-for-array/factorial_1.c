#include <stdio.h>

int main() {
    long long n, ans = 0;
    scanf("%lld", &n);
    long long term = 1;
    for(long long i = 1; i <= n; i++) {
        term = (term * (i % 10007)) % 10007;
        ans += term;
        ans %= 10007;
    }
    printf("%lld", ans);
    return 0;
}