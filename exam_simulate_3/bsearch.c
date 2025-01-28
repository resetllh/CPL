#include <stdio.h>
#include <stdlib.h>

int compare(const void * p, const void * q) {
    int num1 = *((int*) p);
    int num2 = *((int*) q);
    if(num1 < num2)
        return -1;
    else if(num1 == num2)
        return 0;
    else
        return 1;
}

int main() {
    int n, q;
    int* a;
    scanf("%d %d", &n, &q);
    a = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int m;
    for(int i = 0; i < q; i++) {
        scanf("%d", &m);
        int* p = bsearch(&m, a, n, sizeof(int), compare);
        if(p == NULL)
            printf("-1\n");
        else
            printf("%d\n", p - a);
    }
    return 0;
}