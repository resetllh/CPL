#include <stdio.h>

void convert_d() {
    char s[20];
    scanf("%s", s);
    int sign = 1;
    int idx = 0;

    if(s[idx] == '-') {
        sign = -1;
        idx++;
    }

    int num = 0;
    while(s[idx]) {
        if(s[idx] >= '0' && s[idx] <= '9')
            num = 10 * num + s[idx] - '0';
        else {
            printf("Radix Error\n");
            return;
        }
        idx++;
    }

    if(num == 0) {
        printf("0 0\n");
        return;
    }

    printf("%d ", num * sign);

    int t[30];
    int idt = 0;
    while(num > 0) {
        t[idt++] = (num % 3);
        num /= 3;
    }
    t[idt] = 0;

    // printf("ternary\n");
    // for(int i = 0; i < idt; i++)
    //     printf("%d ", t[i]);
    // printf("\n");

    int carry = 0;
    for(int i = 0; i <= idt; i++) {
        if(carry + t[i] <= 1) {
            t[i] += carry;
            carry = 0;
        }
        else if(carry + t[i] == 2) {
            t[i] = -1;
            carry = 1;
        }
        else {
            t[i] = 0;
            carry = 1;
        }
    }
    while(t[idt] == 0)
        idt--;
    for(int i = 0; i <= idt; i++)
        t[i] *= sign;
    
    while(idt >= 0) {
        if(t[idt] == -1)
            printf("Z");
        else
            printf("%d", t[idt]);
        idt--;
    }
    printf("\n");
}

void convert_t() {
    char s[20];
    scanf("%s", s);
    int sum = 0;
    for(int i = 0; s[i]; i++) {
        if(s[i] != '1' && s[i] != '0' && s[i] != 'Z') {
            printf("Radix Error\n");
            return;
        }
        if(s[i] == '1')
            sum = 3 * sum + 1;
        else if(s[i] == '0')
            sum = 3 * sum;
        else
            sum = 3 * sum - 1;
    }
    printf("%d %s\n", sum, s);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char ops[2];
        scanf("%s", ops);
        if(ops[0] == 'd') {
            convert_d();
        }
        else {
            convert_t();
        }
    }
    return 0;
}