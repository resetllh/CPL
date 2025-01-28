#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T > 0) {
        int n, m;
        scanf("%d %d", &n, &m);
        int* a = malloc(n * sizeof(int));
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < m; i++) {
            int x, val;
            scanf("%d", &x);
            val = a[x - 1];
            for(int j = x - 2; j >= 0; j--)
                a[j + 1] = a[j];
            a[0] = val;
        }
        bool flag = true;
        for(int i = 0; i < n - 1; i++)
            if(a[i] > a[i + 1]) {
                flag = false;
                break;
            }
        free(a);
        if(flag)
            printf("I love C programming language\n");
        else
            printf("mayi is a good teacher\n");
        T--;
    }
    return 0;
}