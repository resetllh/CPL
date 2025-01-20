#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int a, b;
    char op[3];
    int i = 0;
    while(scanf("%d %s %d", &a, op, &b) != EOF) {
        if(i != 0) printf("\n");
        i += 1;
        if(strlen(op) == 1) {
            switch (op[0])
            {
            case '+':
                printf("%d", a + b);
                break;
            case '-':
                printf("%d", a - b);
                break;
            case '*':
                printf("%d", a * b);
                break;
            case '%':
                printf("%d", a % b);
                break;
            case '/':
                printf("%d", a / b);
                break;
            }       
        }
        else {
            switch (op[0])
            {
            case '/':
                printf("%.3f", (float) a / b);
                break;
            case '*':
                printf("%d", (int) pow(a, b));
                break;
            }
        }
    }
}