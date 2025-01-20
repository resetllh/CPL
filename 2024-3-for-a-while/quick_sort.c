#include <stdio.h>
int a[10000000];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int value = a[k - 1];
    int l = 0, r = n-1;
    while(l != r) {
        while(l != r && a[l] < value) l++;
        while(r != l && a[r] >= value) r--;
        if(l != r) {
            int temp = a[l];
            a[l] = a[r];
            a[r] = temp;
        }
    }
    for(r = 0; r < n; r++) {
        if(a[r] == value) break;
    }
    int temp = a[l];
    a[l] = a[r];
    a[r] = temp;
    for(int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if(i != n - 1) printf(" ");
    }
    return 0;
}