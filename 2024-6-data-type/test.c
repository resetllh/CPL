#include <stdio.h>

int main() {
    int x = -56;
    printf("%x\n", x);
    printf("%x\n", x >> 31);
    printf("%x\n", x << 31);
    return 0;
}