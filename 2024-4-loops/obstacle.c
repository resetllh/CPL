#include <stdio.h>
#include <stdbool.h>

bool in_line(int x1, int x2, int x3) {
    if(x1 <= x3 && x3 <= x2) return true;
    if(x2 <= x3 && x3 <= x1) return true;
    return false;
}

int main() {
    int xa, ya, xb, yb, xc, yc;
    scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);
    
    int l1 = xb - xa;
    int l2 = yb - ya;
    int step1 = l1 < 0 ? -l1: l1;
    int step2 = l2 < 0 ? -l2: l2;
    int step = step1 + step2;

    if(xa != xb && ya != yb) {
        printf("%d\n", step);
        if((yc == ya && in_line(xa, xb, xc)) ||
           (xc == xb && in_line(ya, yb, yc)) ) {
            for(int i = 0; i < step2; i++) {
                if(l2 > 0) printf("U");
                else printf("D");
            }
            for(int i = 0; i < step1; i++) {
                if(l1 > 0) printf("R");
                else printf("L");
            }
        }
        else {
            for(int i = 0; i < step1; i++) {
                if(l1 > 0) printf("R");
                else printf("L");
            }
            for(int i = 0; i < step2; i++) {
                if(l2 > 0) printf("U");
                else printf("D");
            }
        }
    }
    else if(xa == xb) {
        if(xc == xa && in_line(ya, yb,yc)) {
            printf("%d\n", step + 2);
            printf("L");
            for(int i = 0; i < step2; i++) {
                if(l2 > 0) printf("U");
                else printf("D");
            }
            printf("R");
        }
        else {
            printf("%d\n", step);
            for(int i = 0; i < step2; i++) {
                if(l2 > 0) printf("U");
                else printf("D");
            }
        }
    }
    else if(ya == yb) {
        if(yc == ya && in_line(xa, xb, xc)) {
            printf("%d\n", step + 2);
            printf("U");
            for(int i = 0; i < step1; i++) {
                if(l1 > 0) printf("R");
                else printf("L");
            }
            printf("D");
        }
        else {
            printf("%d\n", step);
            for(int i = 0; i < step1; i++) {
                if(l1 > 0) printf("R");
                else printf("L");
            }
        }
    }
    return 0;
}