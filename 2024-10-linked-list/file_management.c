#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node{
    char name[15];
    struct node* left;
    struct node* right;
} node;

void free_node(node* a) {
    if(a->left != NULL) free_node(a->left);
    if(a->right != NULL) free_node(a->right);
    free(a);
}

void add(node* a, node* b) {
    if(b->left == NULL) 
        b->left = a;
    else 
        b->right = a;
}

void remove_node(node* a, node* b) {
    if(b->left != NULL && strcmp(a->name, b->left->name) == 0) {
        b->left = NULL;
    }
    else b->right = NULL;
    free(a);
}

node* find_node(node* a, char* name) {
    if(a == NULL) return NULL;
    if(strcmp(a->name, name) == 0) return a;
    node* p = find_node(a->left, name);
    node* q = find_node(a->right, name);
    if(p != NULL) return p;
    else return q;
}

node* find_par(node* a, node* head) {
    if(head == a || head == NULL || head->left == a || head->right == a) return head;
    node* p = find_par(a, head->left);
    node* q = find_par(a, head->right);
    if(p != NULL) return p;
    else return q;
}

node* init(int n) {
    char a[15], b[15];
    node* head = NULL;
    for(int i = 0; i < n; i++) {
        scanf("%s %s", a, b);
        if(i == 0) {
            head = malloc(sizeof(node));
            strcpy(head->name, a);
            head->left = NULL;
            head->right = NULL;
        }
        else {
            node* p = malloc(sizeof(node));
            strcpy(p->name, a);
            p->left = NULL;
            p->right = NULL;
            node* q = find_node(head, b);
            add(p, q);
        }
    }
    return head;
}


int get_sum(node* a) {
    if(a == NULL) return 0;
    else return 1 + get_sum(a->left) + get_sum(a->right);
}

void process(int n, int q) {
    node* head = init(n);
    for(int i = 0; i < q; i++) {
        char a[15], b[15];
        scanf("%s %s", a, b);
        if(a[0] == 'q') {
            node* p = find_node(head, b);
            printf("%d\n", get_sum(p));
        }
        else {
            node* p = find_node(head, b);
            node* q = find_par(p, head);
            remove_node(p, q);
        }
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    process(n, q);
    return 0;
}