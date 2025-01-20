#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int T, cnt = 0;
    char* s = malloc(3000);
    char* t = malloc(3000);
    scanf("%d", &T);
    while(cnt < T) {
        scanf("%s", s);
        char* s1 = strtok(s, ";");
        char* s2 = strtok(NULL, ";");
        char* p1 = strtok(NULL, ";");
        char* p2 = strtok(NULL, ";");
        char* p3 = strtok(NULL, ";");
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        int d1 = atoi(p1);
        int d2 = atoi(p2);
        int size = atoi(p3);
        printf("%d %d %d %d %d\n", l1, l2, d1, d2, size);

        int i1 = 0, i2 = 0, i3 = 0;
        while(true) {
            for(int j = 0; j < d1; j++) {
                if(i1 < l1 && i3 < size - 1) {
                    t[i3] = s1[i1];
                    i1++;
                    i3++;
                }
                else break;
            }
            for(int j = 0; j < d2; j++) {
                if(i2 < l2 && i3 < size - 1) {
                    t[i3] = s2[i2];
                    i2++;
                    i3++;
                }
                else break;
            }
            if((i1 >= l1 && i2 >= l2) || i3 == size - 1) {
                t[i3] = '\0';
                break;
            }
        }
        printf("%s\n", t);
        cnt++;
    }
    free(s);
    free(t);
    return 0;
}