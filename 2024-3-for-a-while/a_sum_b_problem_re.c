#include <stdio.h>
#include <string.h>
char a[10000];
char b[10000];
char s[10000000];

int main() {
    int count = 0;
    while(scanf("%s %s", a, b) != EOF) {
        if(count != 0) printf("\n");
        count++;
        int len1 = strlen(a), len2 = strlen(b);
        int len = len1 > len2 ? len1 + 1 : len2 + 1;
        s[len] = '\0';
        int i = len1 - 1, j = len2 - 1, k = len - 1;
        int carry = 0;
        while(k >= 0) {
            int sum = carry;
            if(i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if(j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            carry = sum / 10;
            s[k] = '0' + sum % 10;
            k--;
        }
        if(s[0] != '0') printf("%s", s);
        else printf("%s", s + 1);
    }
}