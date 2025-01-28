#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct indicator{
    int id1;
    int id2;
    int l1;
    int l2;
} indicator;

int n;
char** rule;
indicator* idc;
char s[1000005];

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
    if(rule[i][0] == '.') idc[i].id1 = 1;
    else if(rule[i][0] == '^') idc[i].id1 = 2;
    else idc[i].id1 = 3;

    
    if(rule[i][idc[i].l2 - 2] == '.') idc[i].id2 = 1;
    else if(rule[i][idc[i].l2 - 2] == '^') idc[i].id2 = 2;
    else idc[i].id2 = 3;

    // printf("rule[i]: %s l1:%d l2:%d id1: %d id2: %d\n", rule[i], idc[i].l1, idc[i].l2, idc[i].id1, idc[i].id2);

    rule[i][idc[i].l2 - 3] = '\0';
    rule[i][k - 1] = '\0';
}

char* string_a(int i) {
    char* p = &rule[i][idc[i].l1];
    return p;
}

char* string_b(int i) {
    char* p = &rule[i][idc[i].l2];
    return p;
}

int main() {
    scanf("%d", &n);
    rule = malloc(n * sizeof(char *));
    idc = malloc(n * sizeof(indicator));
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
            // printf("p: %s q: %s id1: %d id2: %d\n", p, q, idc[i].id1, idc[i].id2);
            char* r = strstr(s, p);
            int len1 = strlen(s);
            int len2 = strlen(p);
            if(r == NULL)
                continue;
            else if(idc[i].id1 == 3)
                r = s + len1 - len2;
            // printf("strlen r %d strlen p %d\n", strlen(r), strlen(p));
            if( (idc[i].id1 == 1 && r != NULL) ||
                (idc[i].id1 == 2 && r == s) ||
                (idc[i].id1 == 3 && strcmp(r, p) == 0)) {
                flag = true;
                if(idc[i].id2 == 1) {
                    // printf("process1 ");
                    char t[1000005];
                    strcpy(t, r + strlen(p));
                    r[0] = '\0';
                    strcat(s, q);
                    strcat(s, t);
                }
                else if(idc[i].id2 == 2) {
                    // printf("process2 ");
                    char t[1000005];
                    strcpy(t, r + strlen(p));
                    r[0] = '\0';
                    strcat(s, t);
                    strcpy(t, q);
                    strcat(t, s);
                    strcpy(s, t);
                }
                else {
                    // printf("process3 ");
                    char t[1000005];
                    strcpy(t, r + strlen(p));
                    r[0] = '\0';
                    strcat(s, t);
                    strcat(s, q);
                }
                // printf("after process: %s\n", s);
            }
            if(flag)
                break;
        }
    }
    printf("%s", s);
    return 0;
}