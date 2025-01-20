#include <stdio.h>
#include <stdlib.h>

int a[1000005];

int compare_int(const void * p1,const void * p2) {
    return *(int*)p1 - *(int*)p2;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < q; i++) {
        int num;
        scanf("%d", &num);
        int* pointer = bsearch(&num, a, n, sizeof(a[0]), compare_int);
        if(pointer == NULL) printf("-1\n");
        else printf("%d\n", pointer - a);
    }
    return 0;
}