#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    char c;
    struct node* prev;
    struct node* next;
    struct node* last_same;
} node;

node* head = NULL;
node* last_upper = NULL;
node* last_lower = NULL;

bool is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

void insert(char c) {
    if(head == NULL) {
        node* new_node = malloc(sizeof(node));
        new_node->c = c;
        new_node->prev = NULL;
        new_node->next = NULL;
        new_node->last_same = NULL;
        head = new_node;
        if(is_lower(c)) last_lower = head;
        else last_upper = head;
    }
    else {
        node* new_node = malloc(sizeof(node));
        new_node->c = c;
        new_node->prev = head;
        head->next = new_node;
        new_node->next = NULL;
        if(is_lower(c)) {
            new_node->last_same = last_lower;
            last_lower = new_node;
        }
        else {
            new_node->last_same = last_upper;
            last_upper = new_node;
        }
        head = new_node;
    }
}

void remove_upper() {
    if(last_upper == NULL) return;
    if(last_upper->prev != NULL && last_upper->next != NULL) {
        node* p = last_upper->prev;
        node* q = last_upper->next;
        node* r = last_upper;
        last_upper = last_upper->last_same;
        p->next = q;
        q->prev = p;
        free(r);
    }
    else if(last_upper->prev == NULL && last_upper->next == NULL) {
        free(last_upper);
        head = NULL;
        last_upper = NULL;
        last_lower = NULL;
    }
    else if(last_upper->prev == NULL) {
        node* p = last_upper->next;
        p->prev = NULL;
        free(last_upper);
        last_upper = NULL;
    }
    else {
        node* p = last_upper;
        last_upper = last_upper->last_same;
        head = p->prev;
        head->next = NULL;
        free(p);
    }
}

void remove_lower() {
    if(last_lower == NULL) return;
    if(last_lower->prev != NULL && last_lower->next != NULL) {
        node* p = last_lower->prev;
        node* q = last_lower->next;
        node* r = last_lower;
        last_lower = last_lower->last_same;
        p->next = q;
        q->prev = p;
        free(r);
    }
    else if(last_lower->prev == NULL && last_lower->next == NULL) {
        free(last_lower);
        head = NULL;
        last_upper = NULL;
        last_lower = NULL;
    }
    else if(last_lower->prev == NULL) {
        node* p = last_lower->next;
        p->prev = NULL;
        free(last_lower);
        last_lower = NULL;
    }
    else {
        node* p = last_lower;
        last_lower = last_lower->last_same;
        head = p->prev;
        head->next = NULL;
        free(p);
    }
}


void display() {
    node* p = head;
    while(p != NULL) {
        printf("%c", p->c);
        p = p->prev;
    }
    printf("\n");
}

void show(int k) {
    node* p = head;
    for(int i = 0; i < k - 1; i++) p = p->prev;
    while(p != NULL) {
        printf("%c", p->c);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int Q;
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++) {
        char s[1000000];
        scanf("%s", s);
        if(s[0] != '?') {
            for(int j = 0; s[j]; j++) {
                if(s[j] == 'm') remove_lower();
                else if(s[j] == 'M') remove_upper();
                else insert(s[j]);
                display();
            }
        }
        else {
            int k;
            scanf("%d", &k);
            show(k);
        }
    }
    return 0;
}