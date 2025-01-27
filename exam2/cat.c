#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;

int N, M;
ll R, D;
ll* a;

bool check_ok(ll l) {
    int num = 0;
    ll sum = 0;
    for(int i = 0; i < N; i++)
        if(a[i] > l && a[i] < R) {
            num++;
            sum += a[i] - l;
        }
    return (num >= M) && (sum >= D);
}

int main() {
    scanf("%d %lld %d %lld", &N, &R, &M, &D);
    a = malloc(N * sizeof(ll));
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    ll l = -1, r = R;
    if(check_ok(0)) {
        l = 0;
        while(r - l > 1) {
            ll mid = (l + r) / 2;
            if(check_ok(mid))
                l = mid;
            else
                r = mid;
        }
    }
    printf("%lld", l);
    free(a);
    return 0;
}