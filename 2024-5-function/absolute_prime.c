#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int reverse(int n) {
    int rev = 0;
    while(n != 0) {
        int last = n % 10;
        rev = 10 * rev + last;
        n = (n - last) / 10;
    }
    return rev;
}

int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 2; i <= n; i++) {
        if(is_prime(i) && is_prime(reverse(i))) {
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}