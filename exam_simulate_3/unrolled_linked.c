#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define B 500

typedef struct node{
    int size;
    char val[B];
    struct node* next;
} node;

node* head = NULL;

void init(int n) {
    head = malloc(sizeof(node));
    head->next = NULL;

    char s[n + 1];
    scanf("%s", s);

    node* p = head;
    int l = n, i = 0;
    while(l > 0) {
        if(l > B) {
            p->next = malloc(sizeof(node));
            p = p->next;
            p->size = B;
            p->next = NULL;
            for(int j = 0; j < B; j++)
                p->val[j] = s[i++];
            l -= B;
        }
        else {
            p->next = malloc(sizeof(node));
            p = p->next;
            p->size = l;
            p->next = NULL;
            for(int j = 0; j < l; j++)
                p->val[j] = s[i++];
            l = 0;
        }
    }
}

void query(int idx) {
    node* p = head->next;
    while(idx > p->size) {
        idx -= p->size;
        p = p->next;
    }
    printf("%c\n", p->val[idx - 1]);
}

void display(node* p) {
    printf("display:\n");
    while (p != NULL)
    {
        for(int i = 0; i < p->size; i++)
            printf("%c ", p->val[i]);
        printf("--->");
        p = p->next;
    }
    printf("\n");
}

bool merge(node*p) {
    if(p == head)
        return false;
    node* q = p->next;
    if(q != NULL && p->size + q->size <= B) {
        for(int i = 0; i < q->size; i++)
            p->val[p->size + i] = q->val[i];
        p->size += q->size;
        p->next = q->next;
        free(q);
        return true;
    }
    return false;
}

void insert(char* s, int index) {
    node* h = malloc(sizeof(node));
    h->next = NULL;
    node* p = h;
    int l = strlen(s), i = 0;
    while(l > 0) {
        if(l > B) {
            p->next = malloc(sizeof(node));
            p = p->next;
            p->size = B;
            p->next = NULL;
            for(int j = 0; j < B; j++)
                p->val[j] = s[i++];
            l -= B;
        }
        else {
            p->next = malloc(sizeof(node));
            p = p->next;
            p->size = l;
            p->next = NULL;
            for(int j = 0; j < l; j++)
                p->val[j] = s[i++];
            l = 0;
        }
    }
    node* q = h->next;
    // display(q);
    free(h);

    node *q1, *p1;
    if(index == 0) {
        q1 = head;
        p1 = head->next;
    }
    else {
        q1 = head->next;
        while(index > q1->size) {
            index -= q1->size;
            q1 = q1->next;
        }
        p1 = malloc(sizeof(node));
        p1->size = q1->size - index;
        p1->next = q1->next;
        for(int j = 0; j < p1->size; j++)
            p1->val[j] = q1->val[index + j];
        q1->size = index;
    }
    q1->next = q;
    p->next = p1;
    while(q1 != NULL && merge(q1))
        q1 = q1->next;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    init(n);
    for(int i = 0; i < q; i++) {
        char ops[2];
        scanf("%s", ops);
        int index;
        scanf("%d", &index);
        if(ops[0] == 'Q') {
            query(index);
        }
        else {
            char s[100005];
            scanf("%s", s);
            insert(s, index);
        }
    }
    return 0;
}