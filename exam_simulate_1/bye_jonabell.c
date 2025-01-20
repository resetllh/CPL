#include <stdio.h>

int n, k, b, l;
int life[2000];

int main() {
    scanf("%d %d %d %d", &n, &k, &b, &l);
    int cnt = n;
    int id = 0;
    int now_b = b;
    for(int i = 0; i < n; i++) life[i] = l;
    while(cnt != 1) {
        int step = 0;
        while(step < k - 1) {
            id = (id + 1) % n;
            if(life[id] != 0) step++;
        }
        if(now_b == 0) {
            now_b = b;
            int step = 0;
            while(step < 1) {
                id = (id + 1) % n;
                if(life[id] != 0) step++;
            }
        }
        else {
            if(life[id] > 1) {
                life[id]--;
                now_b--;
                int step = 0;
                while(step < 1) {
                    id = (id + 1) % n;
                    if(life[id] != 0) step++;
                }
            }
            else {
                life[id]--;
                now_b--;
                cnt--;
                int step = 0;
                while(step < 1) {
                    id = (id + 1) % n;
                    if(life[id] != 0) step++;
                }
            }
        }
    }
    printf("%d", id + 1);
    return 0;
}