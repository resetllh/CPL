#include <stdio.h>
int n;
int a[100005];

int poi(int i) {
    if(a[i] == i + 1) return a[i];
    else return poi(a[i] - 1);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        printf("%d ", poi(i));
    return 0;
}