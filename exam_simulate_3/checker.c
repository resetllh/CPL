#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void process(char* s, char* ans, int len) {

    int len1 = strlen(ans);
    for(int i = 0; i < len1 / 2; i++)
        if(ans[i] != ans[len1 - 1 - i]) {
            printf("Wrong Answer!\n");
            return;
        }
        
    if(len1 % 2 == 0 && len % 2 != 0) {
        printf("Wrong Answer!\n");
        return;
    }

    if(len1 % 2 != 0 && len % 2 == 0) {
        printf("Wrong Answer!\n");
        return;
    }

    if(len1 %2 != 0 && len % 2 != 0 && s[len / 2] != ans[len1 / 2]) {
        printf("Wrong Answer!\n");
        return;
    }

    char p[2 * len + 1];
    int j = 0;
    for(int i = 0; i < len / 2; i++) {
        if(s[i] != '?') {
            p[j++] = s[i];
        }
        else if(s[len - 1 - i] != '?') {
            p[j++] = s[len - 1 - i];
        }
        else {
            p[j++] = '*';
            p[j++] = '*';
        }
    }
    bool used[100];
    for(int i = 0; i < 100; i++)
        used[i] = false;

    if(j != len1 / 2) {
        printf("Wrong Answer!\n");
        return;
    }

    int k = 0;
    while(k < j) {
        if(p[k] != '*') {
            if(p[k] == ans[k]) {
                k++;
                continue;
            }
            else {
                printf("Wrong Answer!\n");
                return;
            }
        }
        else {
            int num1 = (ans[k] - '0') * 10 + (ans[k + 1] - '0');
            int num2 = (ans[k + 1] - '0') * 10 + (ans[k] - '0');
            if(used[num1] && used[num2]) {
                printf("Wrong Answer!\n");
                return;
            }
            else if(used[num1])
                used[num2] = true;
            else
                used[num1] = true;
            k += 2;
        }
    }
    printf("Correct.\n");
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T-- > 0) {
        int n;
        scanf("%d", &n);
        char s[n + 1], ans[2 * n + 1];
        scanf("%s \n %s", s, ans);
        process(s, ans, n);
    }
    return 0;
}