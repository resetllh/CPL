#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct monster{
    int x;
    int y;
    int hp;
} monster;

typedef long long ll;

int n;
monster* a;

int pos = 0;
int* x_pos;

int *l_high, *r_high, *l_low, *r_low, *l_hp, *r_hp;

int compare(const void* p, const void* q) {
    monster* p1 = (monster*) p;
    monster* q1 = (monster*) q;
    if((p1->x < q1->x) || ((p1->x == q1->x) && (p1->y < q1->y)))
        return -1;
    else if((p1->x == q1->x) && (p1->y == q1->y))
        return 0;
    else
        return 1;
}

void init() {
    scanf("%d", &n);
    a = malloc(n * sizeof(monster));
    x_pos = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) 
        scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].hp);
    
    qsort(a, n, sizeof(monster), compare);

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            x_pos[pos++] = 0;
            continue;
        }
        if(a[i].x != a[i - 1].x) {
            x_pos[pos++] = i;
        }
    }

    // printf("\nAfter sort n = %d\n", n);
    // for(int i = 0; i < n; i++) {
    //     printf("x = %d y = %d hp = %d\n", a[i].x, a[i].y, a[i].hp);
    // }
    // printf("end\n");

    // printf("\nx id pointer len pos = %d\n", pos);
    // for(int i = 0; i < pos; i++) {
    //     printf("id = %d\n", x_pos[i]);
    // }
    // printf("end\n");
}

void dp() {
    l_high = malloc(pos * sizeof(int));
    l_low = malloc(pos * sizeof(int));
    l_hp = malloc(pos * sizeof(int));
    for(int i = 0; i < pos - 1; i++) {
        int left_start = x_pos[i];
        int right_end = x_pos[i + 1];
        int y_high = (i == 0) ? INT_MIN: l_high[i - 1];
        int y_low = (i == 0) ? INT_MAX: l_low[i - 1];
        int hp_high = (i == 0) ? INT_MIN: l_hp[i - 1];
        for(int j = left_start; j < right_end; j++) {
            if(a[j].y > y_high) y_high = a[j].y;
            if(a[j].y < y_low) y_low =a[j].y;
            if(a[j].hp > hp_high) hp_high = a[j].hp;
        }
        l_high[i] = y_high;
        l_low[i] = y_low;
        l_hp[i] = hp_high;
    }

    // printf("\ndp sequence1:\n");
    // for(int i = 0; i < pos - 1; i++)
    //     printf("y_high = %d y_low = %d hp_high = %d\n", l_high[i], l_low[i], l_hp[i]);

    r_high = malloc(pos * sizeof(int));
    r_low = malloc(pos * sizeof(int));
    r_hp = malloc(pos * sizeof(int));
    for(int i = pos - 2; i >= 0; i--) {
        int left_start = x_pos[i + 1];
        int right_end = (i == pos - 2) ? n: x_pos[i + 2];
        int y_high = (i == pos - 2) ? INT_MIN: r_high[i + 1];
        int y_low = (i == pos - 2) ? INT_MAX: r_low[i + 1];
        int hp_high = (i == pos - 2) ? INT_MIN: r_hp[i + 1];
        for(int j = left_start; j < right_end; j++) {
            if(a[j].y > y_high) y_high = a[j].y;
            if(a[j].y < y_low) y_low =a[j].y;
            if(a[j].hp > hp_high) hp_high = a[j].hp;
        }
        r_high[i] = y_high;
        r_low[i] = y_low;
        r_hp[i] = hp_high;
    }

    // printf("\ndp sequence2:\n");
    // for(int i = 0; i < pos - 1; i++)
    //     printf("y_high = %d y_low = %d hp_high = %d\n", r_high[i], r_low[i], r_hp[i]);

    // printf("\n area\n");
    ll total;
    int x_left = a[0].x;
    int x_riht = a[n - 1].x;
    for(int i = 0; i < pos - 1; i++) {
        int id1 = x_pos[i];
        int id2 = x_pos[i + 1];
        ll x_len_1 = a[id1].x - x_left + 1;
        ll x_len_2 = x_riht - a[id2].x + 1;
        ll y_len_1 = l_high[i] - l_low[i] + 1;
        ll y_len_2 = r_high[i] - r_low[i] + 1;
        ll sum = x_len_1 * y_len_1 * l_hp[i] + x_len_2 * y_len_2 * r_hp[i];
        // printf("x1 %d x2 %d y1 %d y2 %d h1 %d h2 %d sum %d\n", a[id1].x, a[id2].x, y_len_1, y_len_2, l_hp[i], r_hp[i], sum);
        if(i == 0) total = sum;
        else if(sum < total) total = sum;
    }
    
    printf("%d", total);
}

int main() {
    init();
    dp();
    return 0;
}