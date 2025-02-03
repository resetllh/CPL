#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int l;
    int r;
    struct  node* next;
} node;

typedef struct mem{
    int l;
    int r;
    bool is_null;
} mem;

int t = 1;
mem a[5002];
node* head;

void init(int n) {
    head = malloc(sizeof(node));
    head->l = 0;
    head->r = n;
    head->next = NULL;
}

void display() {
    if(head == NULL) {
        printf("NULL\n");
        return;
    }

    node* p = head;
    while(p != NULL) {
        printf("[%d,%d) ", p->l, p->r);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int T, n;
    scanf("%d %d", &T, &n);
    init(n);
    while(T-- > 0) {
        int opt;
        scanf("%d", &opt);
        if(opt == 1) {
            int size;
            scanf("%d", &size);
            node* p = head;
            while(p != NULL && p->r - p->l < size)
                p = p->next;
            if(p == NULL) {
                a[t].is_null = true;
                t++;
                printf("malloc fail\n");
            }
            else if(p->r - p->l > size) {
                a[t].l = p->l;
                a[t].r = p->l + size;
                a[t].is_null = false;
                printf("%d\n", a[t].l);
                t++;
                p->l += size;
            }
            else if(p == head) {
                a[t].l = head->l;
                a[t].r = head->r;
                a[t].is_null = false;
                printf("%d\n", a[t].l);
                t++;
                node* q = head;
                head = head->next;
                free(q);
            }
            else {
                a[t].l = p->l;
                a[t].r = p->r;
                a[t].is_null = false;
                printf("%d\n", a[t].l);
                t++;
                node* q = head;
                while(q->next != p)
                    q = q->next;
                q->next = p->next;
                free(p);
            }
        }
        else if(opt == 2) {
            int id;
            scanf("%d", &id);
            if(a[id].is_null == true) {
                printf("free fail\n");
            }
            else {
                a[id].is_null = true;
                int l = a[id].l;
                int r = a[id].r;
                if(head == NULL) {
                    head = malloc(sizeof(node));
                    head->l = l;
                    head->r = r;
                    head->next = NULL;
                }
                else {
                    node* p = head;
                    while(p != NULL && p->l < r)
                        p = p->next;
                    if(p == head) {
                        if(p->l == r) {
                            head->l = l;
                        }
                        else {
                            node* new_node = malloc(sizeof(node));
                            new_node->l = l;
                            new_node->r = r;
                            new_node->next = head;
                            head = new_node;
                        }
                    }
                    else {
                        node* q = head;
                        while(q->next != p)
                            q = q->next;
                        if(p == NULL) {
                            if(l == q->r) {
                                q->r = r;
                            }
                            else {
                                node* new_node = malloc(sizeof(node));
                                new_node->l = l;
                                new_node->r = r;
                                new_node->next = NULL;
                                q->next = new_node;
                            }
                        }
                        else {
                            if(r == p->l && l > q->r)
                                p->l = l;
                            else if(l == q->r && r < p->l)
                                q->r = r;
                            else if(l > q->r && r < p->l) {
                                node* new_node = malloc(sizeof(node));
                                new_node->l = l;
                                new_node->r = r;
                                new_node->next = p;
                                q->next = new_node;
                            }
                            else {
                                q->r = p->r;
                                q->next = p->next;
                                free(p);
                            }
                        }
                    }
                }
                printf("free success\n");
            }
        }
        else {
            display();
        }
    }
    return 0;
}