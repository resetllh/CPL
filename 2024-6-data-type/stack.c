#include<stdio.h>
#include<string.h>
int id = 0;
char stack[100000];

void push(char s) {
    stack[id++] = s;
}

void pop() {
    if(id >= 1) id--;
    else printf("Empty\n");
}

void top() {
    if(id >= 1)
        printf("%c\n", stack[id - 1]);
    else printf("Empty\n");   
}


void print() {
    if(id >= 1) {
        for(int i = id - 1; i >= 0; i--)
            printf("| %c |\n", stack[i]);
        printf("|===|\n");
    }
    else printf("Empty\n");   
}


int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char ops[10];
        scanf("%s", ops);
        int len = strlen(ops);
        if(len == 5) {
            print();
        }
        else if(len == 4) {
            char s[10];
            scanf("%s", s);
            push(s[0]);
        }
        else {
            if(ops[0] == 'p') pop();
            else top();
        }
    }
    return 0;
}