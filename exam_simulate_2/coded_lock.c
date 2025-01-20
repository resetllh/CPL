#include <stdio.h>
#include <stdbool.h>

int W, N, D;
int a[2000];

int get_count(int i, int j) {
    int k1;
    bool flag1 = false;
    for(long long h1 = 0; h1 <= D; h1++)
        if((a[j] - a[i] + h1 * N) >= 0 && 
        (a[j] - a[i] + h1 * N) % D == 0) {
            flag1 = true;
            k1 = (a[j] - a[i] + h1 * N) / D;
            break;
        }
    int k2;
    bool flag2 = false;
    for(long long h2 = 0; h2 <= D; h2++)
        if((a[i] - a[j] + h2 * N) >= 0 && 
        (a[i] - a[j] + h2 * N) % D == 0) {
            flag2 = true;
            k2 = (a[i] - a[j] + h2 * N) / D;
            break;
        }
    if(flag1 && flag2) return k1 < k2 ? k1: k2;
    else if(flag1) return k1;
    else if(flag2) return k2;
    else return -1;
}

int main() {
    scanf("%d %d %d", &W, &N, &D);
    for(int i = 0; i < W; i++)
        scanf("%d", &a[i]);
    int total = 0;
    bool flag = true;
    for(int i = 0; i < W / 2; i++) {
        int cnt = get_count(i, W - 1 - i);
        if(cnt == -1) {
            flag = false;
            break;
        }
        else total += cnt;
    }
    if(flag)
        printf("%d", total);
    else 
        printf("Impossible");
    return 0;
}