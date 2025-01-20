#include <stdio.h>

int m;
int len = 0;
int a[100];


void get_digit() {
    int val = m;
    while(val != 0) {
        int res = val % 5;
        val /= 5;
        a[len++] = res;
    }
}

void convert() {
    int carry = 0;
    for(int i = 0; i < len; i++) {
        int sum = a[i] + carry;
        if(sum <= 2) {
            carry = 0;
            a[i] = sum;
            continue;
        }
        else {
            a[i] = sum - 5;
            carry = 1;
        }
    }
    a[len++] = carry;
}

int count() {
    int cnt = 0;
    for(int i = 0; i < len; i++)
        cnt += a[i] > 0 ? a[i]: -a[i];
    return cnt;
}


int main() {
    scanf("%d", &m);
    if(m == 0) printf("0");
    else {
        get_digit();
        convert();
        printf("%d", count());
    }
    return 0;
}