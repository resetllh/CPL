#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int num;
    int len;
    struct node* prev;
    struct node* next;
} node;

void insert(node* p, int num) {
    node* q = malloc(sizeof(node));
    q->num = num;
    q->next = p;
    q->prev = p->prev;
    q->prev->next = q;
    p->prev = q;
    p->len++;
}



int n, m;
node** ls;

node* get(int x, int r) {
    node* tail = ls[x - 1];
    int len = tail->len;
    if(r < len - r) {
        node* p = tail->next;
        for(int i = 1; i < r; i++)
            p = p->next;
        return p;
    }
    else {
        node* p = tail->prev;
        for(int i = 0; i < len - r; i++)
            p = p->prev;
        return p;
    }
}

void link_back(int x, int y) {
    if(x == y) return;
    if(x < 1 || x > n) return;
    if(y < 1 || y > n) return;
    node* tail1 = ls[x - 1];
    node* tail2 = ls[y - 1];
    if(tail2->next == tail2) return;
    tail1->len += tail2->len;
    tail2->len = 0;
    node* p = tail2->next;
    node* q = tail2->prev;
    tail2->next = tail2;
    tail2->prev = tail2;
    p->prev = tail1->prev;
    tail1->prev->next = p;
    q->next = tail1;
    tail1->prev = q;
}

void link_front(int x, int y) {
    if(x == y) return;
    if(x < 1 || x > n) return;
    if(y < 1 || y > n) return;
    node* tail1 = ls[x - 1];
    node* tail2 = ls[y - 1];
    if(tail2->next == tail2) return;
    tail1->len += tail2->len;
    tail2->len = 0;
    node* p = tail2->next;
    node* q = tail2->prev;
    tail2->next = tail2;
    tail2->prev = tail2;
    q->next = tail1->next;
    tail1->next->prev = q;
    tail1->next = p;
    p->prev = tail1;
}

void cut(int x, int p, int q) {
    node* tail = ls[x - 1];
    if(p > q) return;
    if(p < 1 || p > tail->len) return;
    if(q < 1 || q > tail->len) return;
    node* p1 = get(x, p);
    node* p2 = get(x, q);
    tail->len -= (q - p + 1);
    p1->prev->next = p2->next;
    p2->next->prev = p1->prev;
    while(p1 != p2) {
        node* q = p1;
        p1 = p1->next;
        free(q);
    }
    free(p1);
    return;
}

void rotate(int x, int p, int q) {
    node* tail = ls[x - 1];
    if(p > q || p == q) return;
    if(p < 1 || p > tail->len) return;
    if(q < 1 || q > tail->len) return;
    node* p1 = get(x, p);
    node* p2 = get(x, q);
    node* p3 = p2->prev;
    p3->next = p2->next;
    p2->next->prev = p3;
    p2->next = p1;
    p2->prev = p1->prev;
    p1->prev->next = p2;
    p1->prev = p2;
    return;
}

void reverse(int x, int p, int q) {
    node* tail = ls[x - 1];
    if(p > q || p == q) return;
    if(p < 1 || p > tail->len) return;
    if(q < 1 || q > tail->len) return;
    node* p1 = get(x, p);
    node* p2 = get(x, q);
    int len = q - p + 1;
    while(len > 0) {
        int num1 = p1->num;
        int num2 = p2->num;
        p1->num = num2;
        p2->num = num1;
        p1 = p1->next;
        p2 = p2->prev;
        len -= 2;
    }
    return;
}

void display() {
    for(int i = 0; i < n; i++) {
        node* p = ls[i]->next;
        while(p != ls[i]) {
            printf("%d ", p->num);
            p = p->next;
        }
        if(ls[i]->len != 0)
            printf("\n");
    }
}

int main() {
    scanf("%d %d", &n, &m);
    ls = malloc(n * sizeof(node*));
    for(int i = 0; i < n; i++) {
        int l;
        scanf("%d", &l);
        ls[i] = malloc(sizeof(node));
        ls[i]->len = 0;
        ls[i]->prev = ls[i];
        ls[i]->next = ls[i];
        for(int j = 0; j < l; j++) {
            int num;
            scanf("%d", &num);
            insert(ls[i], num);
        }
    }

    for(int i = 0; i < m; i++) {
        char s[10];
        scanf("%s", s);
        if(strcmp(s, "link") == 0) {
            char t[10];
            scanf("%s", t);
            if(strcmp(t, "back") == 0) {
                int x, y;
                scanf("%d %d", &x, &y);
                link_back(x, y);
            }
            else {
                int x, y;
                scanf("%d %d", &x, &y);
                link_front(x, y);
            }
        }
        else if(strcmp(s, "cut") == 0) {
            int x, p, q;
            scanf("%d %d %d", &x, &p, &q);
            cut(x, p, q);
        }
        else if(strcmp(s, "rotate") == 0) {
            int x, p, q;
            scanf("%d %d %d", &x, &p, &q);
            rotate(x, p, q);
        }
        else if(strcmp(s, "reverse") == 0) {
            int x, p, q;
            scanf("%d %d %d", &x, &p, &q);
            reverse(x, p, q);
        }
    }
    display();
    return 0;
}