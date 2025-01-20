#include <stdio.h>

int a[1000005];

int main() {
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) 
        scanf("%d", &a[i]);
    
    int tag = 0;
    for(int i = 1; i < m; i++) {
        if(a[i] >= a[i - 1])
            continue;
        else {
            tag = -1;
            break;
        }
    }
    if(tag == 0) {
        tag = 1;
        for(int i = 2; i < m; i++) {
            if(a[i] + a[i - 2] > 2 * a[i - 1])
                continue;
            else {
                tag = 0;
                break;
            }
        }
    }
    printf("%d", tag);
    return 0;
}