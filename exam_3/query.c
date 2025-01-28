#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, q;
int* a;

int compare(const void * p,const void * q) {
    int num1 = * ((int*) p);
    int num2 = * ((int*) q);
    if(num1 < num2)
        return -1;
    else if(num1 == num2)
        return 0;
    else
        return 1;
}

void init() {
    scanf("%d", &n);
    a = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), compare);
}



bool query(int m) {
    int* p = bsearch(&m, a, n, sizeof(int), compare);
    return p != NULL;
}

void process() {
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        int m;
        scanf("%d", &m);
        if(query(m))
            printf("1\n");
        else
            printf("0\n");       
    }
}

int main() {
    init();
    process();
    free(a);
    return 0;
}