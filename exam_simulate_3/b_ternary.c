#include <stdio.h>
#include <stdlib.h>

void convert_d_to_t() {
    char s[20];
    scanf("%s", s);
    int sign = 1, i = 0;
    if(s[0] == '-') {
        sign = -1;
        i = 1;
    }
    int sum = 0;
    for(; s[i]; i++) {
        if(s[i] < '0' || s[i] > '9') {
            printf("Radix Error\n");
            return;
        }
        sum = 10 * sum + (s[i] - '0');
    }
    printf("sum %d ", sum);
    if(sum == 0) {
        printf("0\n");
        return;
    }
    int a[40];
    i = 0;
    while(sum != 0) {
        a[i] = sum % 3;
        i++;
        sum = sum / 3;
    }
    a[i] = sum;
    for(int j = 0; j <= i; j++)
        printf("%d", a[j]);
    printf(" ");
    int carry = 0, j;
    for(j = 0; j <= i; j++) {
        a[j] += carry;
        if(a[j] >= 2) {
            a[j] -= 3;
            carry = 1;
        }
    }
    while(a[j] == 0) j--;
    while(j >= 0) {
        if(a[j] * sign == 1)
            printf("1");
        else if(a[j] * sign == -1)
            printf("Z");
        else
            printf("0");
        j--;
    }
    printf("\n");
    return;
}

void convert_t_to_d() {

}

int main() {
    int n;
    scanf("%d", &n);
    while(n-- > 0) {
        char s[10];
        scanf("%s", s);
        if(s[0] == 'd')
            convert_d_to_t();
        else
            convert_t_to_d();
    }
}