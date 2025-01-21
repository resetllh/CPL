#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[25];
    struct node *next;
} node;

node** list = NULL;

void get_loop() {
    node* p =list[0];
    node* q = list[0];
    int step = 0;
    do {
        p = p->next;
        q = q->next;
        if(q == NULL) {
            printf("-1");
            return;
        }
        q = q->next;
        if(q == NULL) {
            printf("-1");
            return;
        }
        step++;
    } while(p != q);
    p = list[0];
    while(p != q) {
        p = p->next;
        q = q->next;
    }
    printf("%s", p->name);
}

int main() {
    int n;
    scanf("%d", &n);
    list = malloc(n * sizeof(node*));
    for(int i = 0; i < n; i++) {
        list[i] = malloc(sizeof(node));
        list[i]->next = NULL;
    }
    for(int i = 0; i < n; i++) {
        scanf("%s", list[i]->name);
        int j;
        scanf("%d", &j);
        j--;
        if(j >=0 && j < n)
            list[i]->next = list[j];
    }
    get_loop();
    return 0;
}