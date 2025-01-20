#include <stdio.h>

int a[1000005];
int b[1000005];

int find(int upper, int n) {
    int l = 0, r = n - 1;
    while(l < r) {
        int mid = (l + r) / 2;
        if(a[mid] < upper) {
            if(a[mid + 1] > upper) return a[mid];
            else l = mid + 1;
        }
        else if(a[mid] == upper) return a[mid];
        else r = mid - 1;
    }
    return a[r];
}

int main() {
    int n, m, t;
    scanf("%d %d %d", &n, &m, &t);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int j = 0; j < m; j++) scanf("%d", &b[j]);

    int flag = 0;
    int ans = 2147483647;
    for(int j = 0; j < m; j++) {
        int upper = t - b[j];
        if(upper < a[0]) continue;
        else {
            flag = 1;
            printf("find %d in a\n", upper);
            int lower = find(upper, n);
            printf("find lower = %d in a\n", lower);
            int gap = upper - lower;
            if(gap < ans) ans = gap;
        }
    }
    if(flag == 1) printf("%d", ans);
    else printf("-1");
    return 0;
}