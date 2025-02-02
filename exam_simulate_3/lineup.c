#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int num;
    struct node* right;
    struct node* down;
} node;

node* head = NULL;
int n, m;

void init() {
    head = malloc(sizeof(node));
    head->right = NULL;
    head->down = NULL;
    node* poi = head;
    for(int i = 0; i < n; i++) {
        node* new_node = malloc(sizeof(node));
        new_node->right = NULL;
        new_node->down = NULL;
        poi->down = new_node;
        poi = new_node;
    }
    poi = head;
    for(int i = 0; i < m; i++) {
        node* new_node = malloc(sizeof(node));
        new_node->right = NULL;
        new_node->down = NULL;
        poi->right = new_node;
        poi = new_node;
    }
    node* qoi = head;
    poi = qoi;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            node* new_node = malloc(sizeof(node));
            new_node->num = i * m + j;
            new_node->right = NULL;
            new_node->down = NULL;
            poi->right->down = new_node;
            poi->down->right = new_node;
            poi = poi->right;
        }
        qoi = qoi->down;
        poi = qoi;
    }
}

node* find(int x1, int y1) {
    node* p = head;
    for(int i = 0 ; i < x1; i++)
        p = p->down;
    for(int i = 0; i < y1; i++)
        p = p->right;
    return p;
}

void fix(node* p1, node* p2, node* q, int h, int w) {
    node* q1 = q;
    for(int i = 0; i < h; i++) {
        p1->right = q1;
        if(i == h - 1)
            break;
        p1 = p1->down;
        q1 = q1->down;
    }
    if(p1->down == NULL) {
        for(int i = 0; i < w; i++) {
            q1->down = NULL;
            q1 = q1->right;
        }
    }
    else {
        p1 = p1->down->right;
        for(int i = 0; i < w; i++) {
            q1->down = p1;
            q1 = q1->right;
            p1 = p1->right;
        }
    }

    node* q2 = q;
    for(int i = 0; i < w; i++) {
        p2->down = q2;
        if(i == w - 1)
            break;
        p2 = p2->right;
        q2 = q2->right;
    }
    if(p2->right == NULL) {
        for(int i = 0; i < h; i++) {
            q2->right = NULL;
            q2 = q2->down;
        }
    }
    else {
        p2 = p2->right->down;
        for(int i = 0; i < h; i++) {
            q2->right = p2;
            q2 = q2->down;
            p2 = p2->down;
        }
    }
}

void process() {
    int x1, y1, x2, y2, x3, y3, x4, y4, a;
    scanf("%d %d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &a);
    int h = x2 - x1 + 1;
    int w = y2 - y1 + 1;

    node* p1 = find(x1, y1 - 1);
    node* p2 = find(x1 - 1, y1);
    node* q1 = find(x3, y3);
    node* q2 = find(x1, y1);

    fix(p1, p2, q1, h, w);

    p1 = find(x3, y3 - 1);
    p2 = find(x3 - 1, y3);
    fix(p1, p2, q2, h, w);

    node* p = head;
    for(int i = 0; i < a; i++)
        p = p->down;
    p = p->right;
    long long sum = 0;
    while(p != NULL) {
        sum += p->num;
        p = p->right;
    }
    printf("%lld\n", sum);
}

int main() {
    scanf("%d %d", &n, &m);
    init();
    int q;
    scanf("%d", &q);
    while(q-- > 0)
        process();
    return 0;
}