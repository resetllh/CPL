#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char ch;
    struct node* next;
} node;

typedef struct list{
    node* head;
    node* tail;
} list;

void display(list* l) {
    node* p = l->head->next;
    while(p != NULL) {
        printf("%c", p->ch);
        p = p->next;
    }
    printf("\n");
}

list* init() {
    char s[105];
    scanf("%s", s);
    list* l = malloc(sizeof(list));
    l->head = malloc(sizeof(node));
    l->tail = l->head;

    for(int i = 0; s[i]; i++) {
        node* new_node = malloc(sizeof(node));
        new_node->ch = s[i];
        new_node->next = NULL;
        l->tail->next = new_node;
        l->tail = new_node;
    }
    return l;
}

bool match(node* p, node* q) {
    node* r1 = p->next;
    node* r2 = q;
    while(r2->next != NULL) {
        if(r1 != NULL && r1->ch == r2->ch) {
            r1 = r1->next;
            r2 = r2->next;
        }
        else break;
    }
    if(r1 == NULL || r1->ch != r2->ch) return false;
    r2->next = r1->next;
    return true;
}

void replace(list* s, list* r1, list* r2) {
    node* p = s->head;
    
}

int main() {
    list* s = init();
    int n, m;
    scanf("%d %d", &n, &m);

    list *r1[n], *r2[n];
    for(int i = 0; i < n; i++) {
        r1[i] = init();
        r2[i] = init();
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            replace(s, r1[j], r2[j]);
    }

    display(s);
    return 0;
}