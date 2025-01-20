#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a < b) {
        int temp = b;
        b = a;
        a = temp;
    }
    if(b < c) {
        int temp = b;
        b = c;
        c = temp;
    }
    if(a < b) {
        int temp = b;
        b = a;
        a = temp;
    }
    if(a >= b + c) {
        printf("not triangle");
    }
    else if(a == b && b == c) {
        printf("equilateral triangle");
    }
    else if(b * b + c * c == a * a) {
        printf("right triangle");
    }
    else {
        if(b * b + c * c >= a * a) {
            printf("acute ");
        }
        else {
            printf("obtuse ");
        }
        if(b == c) printf("isosceles ");
        printf("triangle");
    }
    return 0;
}