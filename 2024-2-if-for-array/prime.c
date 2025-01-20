#include <stdio.h>
#define M 50000005
char is_prime[M / 8 + 1];

void setbit(int index) {
    is_prime[index / 8] |= (1 << (index % 8));
}

void clearbit(int index) {
    is_prime[index / 8] &= (~(1 << (index % 8)));
}

int getbit(int index) {
    int x = is_prime[index / 8] & (1 << (index % 8));
    return x != 0 ? 1: 0;
}

int main() {
    int n;
    scanf("%d", &n);
    clearbit(1);
    for(int i = 2; i <= n; i++) setbit(i);
    for(int i=2; (long long)i * i <= n; i++) {
        if(getbit(i)) {
            if((long long) i * i > n) continue;
            for(int j = i * i; j <= n; j += i) {
                clearbit(j);
            }
        }
    }
    int count = 0;
    for(int i = 1; i <= n; i++) if(getbit(i)) count += 1;
    printf("%d", count);
    return 0;
}