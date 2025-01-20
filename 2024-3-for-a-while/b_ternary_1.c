#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char s[20];
        scanf("%s", s);
        int len = strlen(s);
        int ans = 0, flag = 1;
        for(int j = 0; j < len; j++) {
            if(s[j] == '1') {
                ans = 3 * ans + 1;
            }
            else if(s[j] == '0') {
                ans = 3 * ans;
            }
            else if(s[j] == 'Z') {
                ans = 3 * ans - 1;
            }
            else {
                flag = 0;
                break;
            }
        }
        if(i != 0) printf("\n");
        if(flag == 0) {
            printf("Radix Error");
        }
        else {
            printf("%d", ans);
        }
    }
    return 0;
}