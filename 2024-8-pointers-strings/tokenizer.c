#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char *s;
char *t;

bool is_num(char c) {
    return c >= '0' && c <= '9';
}

bool is_char(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_reserved(char* s) {
    bool flag = false;
    if(!(strcmp(s, "const"))) flag = true;
    if(!(strcmp(s, "int"))) flag = true;
    if(!(strcmp(s, "float"))) flag = true;
    if(!(strcmp(s, "double"))) flag = true;
    if(!(strcmp(s, "long"))) flag = true;
    if(!(strcmp(s, "static"))) flag = true;
    if(!(strcmp(s, "void"))) flag = true;
    if(!(strcmp(s, "char"))) flag = true;
    if(!(strcmp(s, "extern"))) flag = true;
    if(!(strcmp(s, "return"))) flag = true;
    if(!(strcmp(s, "break"))) flag = true;
    if(!(strcmp(s, "enum"))) flag = true;
    if(!(strcmp(s, "struct"))) flag = true;
    if(!(strcmp(s, "typedef"))) flag = true;
    if(!(strcmp(s, "union"))) flag = true;
    if(!(strcmp(s, "goto"))) flag = true;
    return flag;
}

bool is_int(char* s) {
    bool flag = true;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(!is_num(*(s + i))) {
            flag = false;
            break;
        }
    }
    return flag;
}

bool is_float(char* s) {
    int len = strlen(s);
    if(len == 1 && *s == '.') return false;
    char* p = strchr(s, '.');
    if(p == NULL) {
        return is_int(s);
    }
    else {
        *p = '\0';
        return is_int(s) && is_int(p + 1);
    }
}

bool is_operator(char* s) {
    bool flag = false;
    if(!(strcmp(s, "+"))) flag = true;
    if(!(strcmp(s, "-"))) flag = true;
    if(!(strcmp(s, "*"))) flag = true;
    if(!(strcmp(s, "/"))) flag = true;
    if(!(strcmp(s, "="))) flag = true;
    if(!(strcmp(s, "=="))) flag = true;
    if(!(strcmp(s, "!="))) flag = true;
    if(!(strcmp(s, ">="))) flag = true;
    if(!(strcmp(s, "<="))) flag = true;
    if(!(strcmp(s, ">"))) flag = true;
    if(!(strcmp(s, "<"))) flag = true;
    return flag;
}

bool is_variable(char* s) {
    bool flag = true;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(!is_num(*(s + i)) && !is_char(*(s + i)) && *(s + i) != '_') {
            flag = false;
            break;
        }
    }
    if(is_num(*s)) flag = false;
    return flag;
}

bool process(char* s) {
    bool flag = false;
    if(*s == '\0') flag = true;
    else if(is_reserved(s)) {
        strcat(t, "reserved ");
        flag = true;
    }
    else if(is_int(s)) {
        strcat(t, "integer ");
        flag = true;
    }
    else if(is_operator(s)) {
        strcat(t, "operator ");
        flag = true;
    }
    else if(is_variable(s)) {
        strcat(t, "variable ");
        flag = true;
    }
    else if(is_float(s)) {
        strcat(t, "float ");
        flag = true;
    }
    return flag;
}

int main() {
    s = malloc(20005);
    t = malloc(20005);
    *t = '\0';
    char *p = s;
    char *q = t;
    bool success = true;
    while(scanf("%s", s) != EOF) {
        for(char *pos = strchr(s, ';'); pos; s = pos + 1, pos = strchr(s, ';')) {
            *pos = '\0';
            if(!process(s)) {
                success = false;
                break;
            }
            else {
                strcat(t, "\n");
            }
        }
        if(success == false) break;
        if(!process(s)) {
            success = false;
            break;
        }
    }
    int len = strlen(t);
    if(success && *(t + len - 1) == '\n') printf("%s", t);
    else printf("Compile Error");
    free(p);
    free(q);
    return 0;
}