#include <stdio.h>

int main() {
    int price;
    scanf("%d", &price);
    int change1 = price / 50;
    price %= 50;
    printf("%d\n", change1);
    int change2 = price / 20;
    price %=20;
    printf("%d\n", change2);
    int change3 = price / 10;
    price %=10;
    printf("%d\n", change3);
    int change4 = price / 5;
    price %=5;
    printf("%d\n", change4);
    int change5=price;
    printf("%d", change5);
    return 0;
}