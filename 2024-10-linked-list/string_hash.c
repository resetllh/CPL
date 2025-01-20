#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node
{
    char* name;
    struct node* next;
} node;

void add(node* head, char* s) {
    node* p = malloc(sizeof(node));
    p->name = malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(p->name, s);
    p->next = head->next;
    head->next = p;
}

bool find(node* head, char* s) {
    node* p = head->next;
    while(p != NULL) {
        if(strcmp(p->name, s) == 0) return true;
        p = p->next;
    }
    return false;
}

int hash(char *s, int n){
    int ret=0;
    for(int i  =0; s[i]; i++) ret = (ret + s[i] * (i + 1)) % n;
    return ret;
}

int main() {
    int m, q;
    scanf("%d %d", &m, &q);
    int n = (int)ceil(m / 20.0);
    node** head = malloc(n * sizeof(node*));
    for(int i = 0; i < n; i++) {
        head[i] = malloc(sizeof(node));
        head[i]->next = NULL;
    }
    for(int i = 0; i < m; i++) {
        char s[1005];
        scanf("%s", s);
        int id = hash(s, n);
        add(head[id], s);
    }
    for(int i = 0; i < q; i++) {
        char s[1005];
        scanf("%s", s);
        int id = hash(s, n);
        if(find(head[id], s))
            printf("Yes\n");
        else 
            printf("No\n");
    }
}