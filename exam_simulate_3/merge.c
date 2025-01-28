#include <stdio.h>

int main() {
    int n1, n2, i1 = 0, i2 = 0;
    scanf("%d", &n1);
    int a[n1];
    for(int i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
        if(a[i] > a[i1])
            i1 = i;
    }
    scanf("%d", &n2);
    int b[n2];
    for(int i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
        if(b[i] > b[i2])
            i2 = i;
    }
    int i = 0, j = 0;
    while(i <= i1 && j <= i2) {
        if(a[i] < b[j]) {
            printf("%d ", a[i]);
            i++;
        }
        else {
            printf("%d ", b[j]);
            j++;
        }
    }
    while(i <= i1) {
        printf("%d ", a[i]);
        i++;
    }
    while(j <= i2) {
        printf("%d ", b[j]);
        j++;
    }

    while(i < n1 && j < n2) {
        if(a[i] > b[j]) {
            printf("%d ", a[i]);
            i++;
        }
        else {
            printf("%d ", b[j]);
            j++;
        }
    }
    while(i < n1) {
        printf("%d ", a[i]);
        i++;
    }
    while(j < n2) {
        printf("%d ", b[j]);
        j++;
    }
    return 0;
}