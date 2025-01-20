#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_legal(char* buf) {
    int len = strlen(buf);
    bool flag = true;
    for(int i = 0; i < len; i++) {
        if(buf[i] - '0' < 0 || buf[i] - '0' > 9) {
            if(i == 0 && buf[i] == '-') continue;
            else {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

void convert(char* buf) {
    int len = strlen(buf);
    int sig = 1;
    int start = 0;
    if(buf[0] == '-') {
        sig = -1;
        start = 1;
    }

    int num = 0;
    for(int i = start; i < len; i++) {
        num = num * 10 + (buf[i] - '0');
    }

    if(num == 0) {
        printf("0");
        return;
    }

    int ans[30];
    int i = 0;
    int carry = 0;
    while(num != 0) {
        if(num % 3 + carry <= 1) {
            ans[i++] = num % 3 + carry;
            carry = 0;
        }
        else if(num % 3 + carry == 2) {
            ans[i++] = -1;
            carry = 1;
        }
        else {
            ans[i++] = 0;
            carry = 1;
        }
        num = num / 3;
        if(num == 0 && carry != 0) {
            ans[i++] = carry;
        }
    }

    for(int j = i - 1; j >= 0; j--) {
        if(sig * ans[j] == -1) printf("%c", 'Z');
        else printf("%d", sig * ans[j]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char buf[20];
        scanf("%s", buf);
        if(!is_legal(buf)) {
            printf("Radix Error");
        }
        else {
            convert(buf);
        }
        printf("\n");
    }
    return 0;
}