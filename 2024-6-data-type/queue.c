#include<stdio.h>
#include<string.h>
int left = 0;
int right = 0;
int queue[100000];

void in(int x) {
    queue[right++] = x;
}

void out() {
    printf("%d\n", queue[left]);
    left++;
}

void cat() {
    int len = right - left;
    printf("%d ",len);
    printf("[");
    for(int i = left; i < right; i++) {
        printf("%d", queue[i]);
        if(i != right - 1 && len > 1) printf(",");
    }
    printf("]\n");
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char ops[10];
        scanf("%s", ops);
        int len = strlen(ops);
        if(len == 2) {
            int x;
            scanf("%d", &x);
            in(x);
        }
        else {
            if(ops[0] == 'O') out();
            else cat();
        }
    }
    return 0;
}