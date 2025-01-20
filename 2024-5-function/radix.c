#include <stdio.h>

int convert(int num, int base) {
    int ans = 0;
    int mul = 1;
    while(num != 0) {
        int last = num % 10;
        if(last >= base) return 0;
        ans += last * mul;
        mul *= base;
        num = (num - last) / 10;
    }
    return ans;
}

int main() {
    int p, q, r;
    scanf("%d %d %d", &p, &q, &r);
    int flag = 0;
    for(int b = 2; b <= 40; b++) {
        int p1 = convert(p, b);
        int q1 = convert(q, b);
        int r1 = convert(r, b);
        if(p1 == 0 || q1 == 0 || r1 == 0) continue;
        if(p1 * q1 == r1) {
            flag = 1;
            printf("%d", b);
            break;
        }
    }
    if(flag == 0) printf("0");
    return 0;
}