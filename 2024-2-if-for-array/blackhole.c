#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    while(n != 495) {
        int h, m, l;
        h = n / 100;
        l = n % 10;
        m = (n - 100 * h) / 10;
        if(h < m) {
            int temp = h;
            h = m;
            m = temp;
        }
        if(m < l) {
            int temp = l;
            l = m;
            m = temp;
        }
        if(h < m) {
            int temp = h;
            h = m;
            m = temp;
        }
        int n1 = 100 * h + 10 * m + l - 100 *l - 10 * m - h;
        if(n1 < n) sum += n - n1;
        n = n1;
    }
    printf("%d", sum);
    return 0;
}