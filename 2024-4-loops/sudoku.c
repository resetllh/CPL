#include <stdio.h>
#include <stdbool.h>

int a[9][9];

int main() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < 9;  i++) {
        bool tag[9] = {0};
        for(int j = 0; j < 9; j++) {
            int num = a[i][j] - 1;
            if(tag[num] == false) tag[num] = true;
            else {
                printf("NO1");
                return 0;
            }
        }
    }
    for(int j = 0; j < 9;  j++) {
        bool tag[9] = {0};
        for(int i = 0; i < 9; i++) {
            int num = a[i][j] - 1;
            if(tag[num] == false) tag[num] = true;
            else {
                printf("NO2");
                return 0;
            }
        }
    }
    for(int k = 0; k < 3; k++) {
        for(int h = 0; h < 3; h++) {
            bool tag[9] = {0};
            for(int i = 3 * k; i < 3 * k + 3; i++) {
                for(int j = 3 * h; j < 3 * h + 3; j++) {
                    int num = a[i][j] - 1;
                    if(tag[num] == false) tag[num] = true;
                    else {
                        printf("NO3");
                        return 0;
                    }
                }
            }
        }
    }
    printf("YES");
    return 0;
}