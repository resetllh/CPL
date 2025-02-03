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
    char s[10005];
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
    while(p != NULL && q != NULL && p->ch == q->ch) {
        p = p->next;
        q = q->next;
    }
    if(q == NULL) return true;
    else return false;
}

void insert(node* p, node* q, list* r) {
    node* head = malloc(sizeof(node));
    head->next = NULL;
    node* s = head;
    node* r1 = r->head->next;
    while(r1 != NULL) {
        s->next = malloc(sizeof(node));
        s = s->next;
        s->ch = r1->ch;
        s->next = NULL;
        r1 = r1->next;
    }
    s->next = q;
    p->next = head->next;
    free(head);
}

void replace(list* s, list* r1, list* r2) {
    node* p = s->head;
    node* q = p->next;
    while(q != NULL) {
        if(match(q, r1->head->next)) {
            node* r = r1->head->next;
            while(r != NULL) {
                node* q1 = q;
                q = q->next;
                free(q1);
                r = r->next;
            }
            insert(p, q, r2);
            while(p->next != q)
                p = p->next;
        }
        else {
            p = p->next;
            q = q->next;
        }
    }
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