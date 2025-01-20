#include <stdio.h>

int main() {
    int hour, minute;
    scanf("%d:%d", &hour, &minute);
    if(hour <= 12) {
        printf("%.2d:%.2d ", hour, minute);
    }
    else {
        printf("%.2d:%.2d ", hour - 12, minute);
    }
    if(hour < 12) {
        printf("a.m.");
    }
    else {
        printf("p.m.");
    }
    return 0;
}