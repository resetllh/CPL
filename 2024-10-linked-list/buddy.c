#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node
{
    int id;
    int size;
    struct node *next;    
} node;

node* init(int n) {
    node* head = malloc(sizeof(node));
    head->id = 0;
    head->size = n;
    head->next = NULL;
    return head;
}

void display(node* head) {
    int l = 0;
    node* p = head;
    while(p != NULL) {
        p = p->next;
        l++;
    }
    printf("%d\n", l);
    p = head;
    while(p != NULL) {
        printf("%d ", p->id);
        p = p->next;
    }
    printf("\n");
}

bool query(int size, node* head) {
    node* p = head;
    while(p != NULL) {
        if(p->size == size && p->id == 0) return true;
        p = p->next;
    }
    return false;
}

node* get_par(node* p, node* head) {
    if(p == head) return head;
    node* q = head;
    while(q->next != p) q = q->next;
    return q;
}

node* split(int size, node* head) {
    node* p = head;
    while(p != NULL) {
        if(p->size >= size && p->id == 0) break;
        p = p->next;
    }
    node* par = get_par(p, head);
    if(par == p) {
        node* p1 = malloc(sizeof(node));
        p1->id = 0;
        p1->size = p->size - 1;
        p1->next = p->next;
        node* p2 = malloc(sizeof(node));
        p2->id = 0;
        p2->size = p->size - 1;
        p2->next = p1;
        free(p);
        return p2;
    }
    else {
        node* p1 = malloc(sizeof(node));
        p1->id = 0;
        p1->size = p->size - 1;
        p1->next = p->next;
        node* p2 = malloc(sizeof(node));
        p2->id = 0;
        p2->size = p->size - 1;
        p2->next = p1;
        free(p);
        par->next = p2;
        return head;
    }
}

void add(int size, int id, node* head) {
    node* p =head;
    while(p->size != size || p->id != 0) p = p->next;
    p->id = id;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    node* head = init(n);
    for(int i = 0; i < q; i++) {
        char ops;
        scanf(" %c", &ops);
        if(ops == 'Q') {
            display(head);
        }
        else {
            int id, size;
            scanf("%d %d", &id, &size);
            size = (int) ceil(log2(size));
            while(!query(size, head)) 
                head = split(size, head);
            add(size, id, head);
        }
    }
    return 0;
}