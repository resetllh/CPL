#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, m, k;
int** a;
int* s;
bool* rest_n;
bool* rest_m;

void init() {
    scanf("%d %d %d", &n, &m, &k);
    a = malloc(n * sizeof(int*));
    rest_n = malloc(n * sizeof(bool));
    for(int i = 0; i < n; i++)
        rest_n[i] = true;
    s = malloc(m * sizeof(int));
    rest_m = malloc(m * sizeof(bool));
    for(int i = 0; i < m; i++)
        rest_m[i] = true;
    for(int i = 0; i < m; i++) {
        int size;
        scanf("%d", &size);
        s[i] = size;
        a[i] = malloc(size * sizeof(int));
        for(int j = 0; j < size; j++)
            scanf("%d", &a[i][j]);
    }
}

int intersection(int id) {
    int count = 0;
    for(int i = 0; i < s[id]; i++)
        if(rest_n[a[id][i] - 1] == true)
            count++;
    return count;
}

void rem(int id) {
    for(int i = 0; i < s[id]; i++)
        rest_n[a[id][i] - 1] = false;
}

void process() {
    for(int i = 0; i < k; i++) {
        int id = -1;
        int max = -1;
        for(int j = 0; j < m; j++) {
            if(rest_m[j] == true) {
                int sec_num = intersection(j);
                if(sec_num > max) {
                    max = sec_num;
                    id = j;
                }
            }
        }
        printf("%d ", id + 1);
        rest_m[id] = false;
        rem(id);
    }
}

void free_space() {
    for(int i = 0; i < n; i++)
        free(a[i]);
    free(a);
    free(s);
    free(rest_n);
    free(rest_m);
}

int main() {
    init();
    process();
    free_space();
    return 0;
}