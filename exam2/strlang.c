#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct indicator{
    int id;
    int l1;
    int l2;
} indicator;

int n;
char** rule;
indicator* idc;

void get_idc(int i) {
    int k = 0, flag = 0;
    for(; rule[i][k]; k++) {
        if(rule[i][k] == '[') {
            if(flag == 0) {
                flag++;
                idc[i].l1 = k + 1;
            }
            else {
                idc[i].l2 = k + 1;
            }
        }
    }
    if(rule[i][0] == '^') idc[i].id = 1;
    else if(rule[i][0] == '$') idc[i].id = 4;
    else if(rule[i][idc[i].l2 - 2] == '.') idc[i].id = 2;
    else idc[i].id = 3;
    rule[i][idc[i].l2 - 3] = '\0';
    rule[i][k - 1] = '\0';
}

char* string_a(int i) {
    char* p = rule[i][idc[i].l1];
    return p;
}

char* string_b(int i) {
    char* p = rule[i][idc[i].l2];
    return p;
}

int main() {
    scanf("%d", &n);
    rule = malloc(n * sizeof(char *));
    idc = malloc(n * sizeof(indicator));
    char s[1000005];
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        int len = strlen(s) + 1;
        rule[i] = malloc(len * sizeof(char));
        strcpy(rule[i], s);
        get_idc(i);
    }

    scanf("%s", s);
    bool flag = true;
    while(flag) {
        flag = false;
        for(int i = 0; i < n; i++) {
            char* p = string_a(i);
            char* q = string_b(i);

            
        }
    }
    printf("%s", s);
    return 0;
}