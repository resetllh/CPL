#include <stdio.h>
#include <string.h>
char stack[100005];
int id = 0;

void push(char s) {
    stack[id++] = s;
}

char top() {
    return stack[id - 1];
}

void pop() {
    id--;
}

int length() {
    return id;
}

void reset() {
    id = 0;
}

void is_legal(char s[]) {
    reset();
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') push(s[i]);
        else {
            if(length() <= 0) {
                printf("False\n");
                return;
            }
            char a = top();
            if((a == '(' && s[i] == ')') || 
            (a == '[' && s[i] == ']') || 
            (a == '{' && s[i] == '}')) pop();
            else {
                printf("False\n");
                return;
            }
        }
    }
    if(length() != 0)
        printf("False\n");
    else 
        printf("True\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        char s[100005];
        scanf("%s", s);
        is_legal(s);
    }
    return 0;
}