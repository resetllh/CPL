#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int last_time;
    int during;
} node;

int compare(const void* p, const void* q) {
    node* p1 = (node*) p;
    node* q1 = (node*) q;
    return p1->last_time - q1->last_time;
}

int main() {
    int n;
    scanf("%d", &n);
    node ddl[n];
    for(int i = 0; i < n; i++) {
        int t, d;
        scanf("%d %d", &t, &d);
        ddl[i].last_time = d;
        ddl[i].during =  t;
    }

    qsort(ddl, n, sizeof(node), compare);
    int t = ddl[n - 1].last_time - ddl[n - 1].during;
    for(int j = n - 2; j >= 0; j--) {
        if(ddl[j].last_time <= t)
            t = ddl[j].last_time - ddl[j].during;
        else
            t = t - ddl[j].during;
        if(t < 0) {
            printf("-1");
            return 0;
        }
    }
    printf("%d", t);
    return 0;
}