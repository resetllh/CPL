#include <stdio.h>

int main() {
    int a[] = {0, 0, 3, 0, 0, 0,
               0, 0, 0, 0, 0, 0,
               0, 14, 15, 16, 0, 18};
    int n;
    scanf("%d", &n);
    int ans1, ans2, ans3;
    for(int i = 0; i < n; i++) {
        int id;
        scanf("%d", &id);
        if(i == 0) {
            ans1 = ans2 =ans3 = a[id - 1];
        }
        else {
            ans1 &= a[id - 1];
            ans2 |= a[id - 1];
            ans3 ^= a[id - 1];
        }
    }
    printf("%d %d %d", ans1, ans2, ans3);
    return 0;
}