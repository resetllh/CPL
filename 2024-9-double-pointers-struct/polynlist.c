#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int p1;
int p2;
int p3;
char var[25];
int a[10005];
int b[10005];
int c[1000005];

void print_poly();

void add() {
    p3 = p1 > p2 ? p1: p2;
    for(int i = 0; i <= p3; i++) {
        c[i] = 0;
        if(i <= p1) c[i] += a[i];
        if(i <= p2) c[i] += b[i];
    }
    while(p3>= 0 && c[p3] == 0) p3--;
    print_poly();
}

void sub() {
    p3 = p1 > p2 ? p1: p2;
    for(int i = 0; i <= p3; i++) {
        c[i] = 0;
        if(i <= p1) c[i] += a[i];
        if(i <= p2) c[i] -= b[i];
    }
    while(p3>= 0 && c[p3] == 0) p3--;
    print_poly();
}

void mul() {
    p3 = p1 + p2;
    for(int i = 0; i <= p3; i++) c[i] = 0;
    for(int i = 0; i <= p1; i++) {
        for(int j = 0; j <= p2; j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    while(p3 >= 0 && c[p3] == 0) p3--;
    print_poly();
}

void print_poly() {
    if(p3 <= 0) printf("0\n");
    else {
        for(int  i = p3; i >= 0; i--) {
            if(i == p3) {
                printf("%d", c[i]);
            }
            else if(c[i] < 0) {
                if(c[i] == -1 && i != 0)
                    printf("-");
                else
                    printf("%d", c[i]);
            }
            else if(c[i] > 0) {
                if(c[i] == 1 && i != 0)
                    printf("+");
                else
                    printf("+%d", c[i]);
            }
            else continue;
            if(i != 0) {
                if(i != 1)
                    printf("%s^%d", var, i);
                else 
                    printf("%s", var);
            }
        }
        printf("\n");
    }
}

int main() {
    scanf("%d %d", &p1, &p2);
    scanf("%s", &var);
    for(int i = p1; i >= 0; i--) scanf("%d", &a[i]);
    for(int i = p2; i >= 0; i--) scanf("%d", &b[i]);
    add();
    sub();
    mul();
    return 0;
}