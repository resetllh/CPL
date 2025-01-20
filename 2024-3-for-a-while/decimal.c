#include <stdio.h>
char s[] = {'0', '1', '2', '3', '4', '5', '6', '7',
            '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int main() {
    int len, N;
    scanf("%d %d", &len, &N);
    getchar();
    int ans = 0;
    int flag_out = 1;
    for(int i = 0; i < len; i++) {
        int flag = 0;
        char digit;
        scanf("%c", &digit);
        for(int j = 0; j < N; j++) {
            if(s[j] == digit) {
                ans = ans * N + j;
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            flag_out = 0;
            break;
        }
    }
    if(flag_out == 0) printf("Error");
    else printf("%d", ans);
    return 0;
}