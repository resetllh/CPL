#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int num;
    struct node* next;
} node;

void push(node* head, int num) {
    node* new_node = malloc(sizeof(node));
    new_node->num = num;
    new_node->next = head->next;
    head->next = new_node;
}

int pop(node* head) {
    int num = head->next->num;
    node* p = head->next;
    head->next = p->next;
    free(p);
    return num;
}

bool is_empty(node* head) {
    return head->next == NULL;
}

void init(node** head, int n) {
    for(int i = 0; i < n; i++) {
        head[i] = malloc(sizeof(node));
        head[i]->next = NULL;
        push(head[i], i + 1);
    }
}

void swap(node** head, int x, int y) {
    while(!is_empty(head[x - 1])) {
        int num = pop(head[x - 1]);
        push(head[y - 1], num);
    }
}

void display(node** head, int n) {
    for(int i = 0; i < n; i++) {
        if(is_empty(head[i])) {
            printf("0\n");
        }
        else  {
            node* reverse = malloc(sizeof(node));
            reverse->next = NULL;
            while(!is_empty(head[i])) {
                int num = pop(head[i]);
                push(reverse, num);
            }
            while(!is_empty(reverse)) {
                int num = pop(reverse);
                printf("%d ", num);
            }
            printf("\n");
        }
    }
}

void process(int n, int m) {
    node** head = malloc(n * sizeof(node*));
    init(head, n);
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        swap(head, x, y);
    }
    display(head, n);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    process(n, m);
    return 0;
}