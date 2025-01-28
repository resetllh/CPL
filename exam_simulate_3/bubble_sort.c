#include <stdio.h>
int a[1000000];

int main() {
    int time;
    int n;
    scanf("%d", &time);
    for(int i = 0; i < time; i++) {
        scanf("%d", &n);
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
        int max = a[0];
        for(int i = 0; i < n; i++) {
            if(a[i] > max) max = a[i];
        }
        if(a[n - 1] != max) {
            printf("No\n");
        }
        else {
            printf("Yes\n");
        }
    }
    return 0;
}