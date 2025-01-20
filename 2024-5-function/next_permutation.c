#include <stdio.h>

int a[3000];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int m = n - 1;
    while(a[m - 1] > a[m]) m--;
    int k = n - 1;
    while(a[k] < a[m - 1]) k--;
    for(int i = 0; i < m - 1; i++) printf("%d ", a[i]);
    printf("%d ", a[k]);
    for(int i = n - 1; i > k; i--) printf("%d ", a[i]);
    printf("%d ", a[m - 1]);
    for(int i = k - 1; i > m - 1; i--) printf("%d ", a[i]);
    return 0;
}