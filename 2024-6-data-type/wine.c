#include <stdio.h>
int val[10005];
int vol[10005];

int main() {
    int n, L;
    int ans = 0;
    scanf("%d %d", &n, &L);
    for(int i = 0; i < n; i++) scanf("%d", &val[i]);
    for(int i = 0; i < n; i++) scanf("%d", &vol[i]);
    for(int i = 0; i < n; i++) {
        int id = i;
        for(int j = id + 1; j < n; j++) 
            if(val[j] > val[id]) id = j;
        int temp = val[i];
        val[i] = val[id];
        val[id] = temp;
        temp = vol[i];
        vol[i] = vol[id];
        vol[id] = temp;
    }
    for(int i = 0; i < n; i++) {
        if(L >= vol[i]) {
            ans += val[i] * vol[i];
            L -= vol[i];
        }
        else {
            ans += val[i] * L;
            L = 0;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}