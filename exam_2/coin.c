#include <stdio.h>
#include <stdbool.h>

int a[9];
int b[3];

bool not_is_line(int i, int j, int k) {
    int x1 = i / 3, y1 = i % 3;
    int x2 = j / 3, y2 = j % 3;
    int x3 = k / 3, y3 = k % 3;
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

int main() {
    for(int i = 0; i < 9; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < 3; i++)
        scanf("%d", &b[i]);
    int ans = 0;
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            for(int k = 0; k < 9; k++) {
                int pro = a[i] * b[0] + a[j] * b[1] + a[k] * b[2];
                if(pro > ans && not_is_line(i, j, k))
                    ans = pro;
            }
    printf("%d", ans);
    return 0;
}