#include <stdio.h>
#include <math.h>

int main() {
    long long N;
    scanf("%lld", &N);
    long long N1 = N, sum = 0;
    int digit = 0;
    while(N1 != 0) {
        digit += 1;
        N1 = (N1 - N1 % 10) / 10;
    }
    N1 = N;
    while(N1 != 0) {
        int reminder = N1 % 10;
        sum += pow(reminder, digit);
        N1 = (N1 - reminder) / 10;
    }
    if(sum == N) printf("%d", digit);
    else printf("0");
    return 0;
}