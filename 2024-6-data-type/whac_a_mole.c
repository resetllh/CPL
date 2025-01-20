#include <stdio.h>
#include <limits.h>

int n, m, d;
int val[700][700];

typedef struct pos
{
    int x;
    int y;
} pos;
pos ans[1000000];
int len = 0;
int max_val = INT_MIN;

int get_left_val(int x, int y, int d) {
    int ans = 0;
    for(int i = 0; i <= d; i++) {
        if(x - d + i >= 1 
        && x - d + i <= n 
        && y - i >= 1
        && y - i <= m) {
            ans += val[x - d + i][y - i];
        }
    }
    for(int i = 1; i <= d; i++) {
        if(x + i >= 1 
        && x + i <= n 
        && y - d + i >= 1
        && y - d + i <= m) {
            ans += val[x + i][y - d + i];
        }
    }
    return ans;
}

int get_right_val(int x, int y, int d) {
    int ans = 0;
    for(int i = 0; i <= d; i++) {
        if(x - d + i >= 1 
        && x - d + i <= n 
        && y + i >= 1
        && y + i <= m) {
            ans += val[x - d + i][y + i];
        }
    }
    for(int i = 1; i <= d; i++) {
        if(x + i >= 1 
        && x + i <= n 
        && y + d - i >= 1
        && y + d - i <= m) {
            ans += val[x + i][y + d - i];
        }
    }
    return ans;
}

int get_total(int x, int y, int d) {
    int ans = 0;
    for(int i = 0; i <= d; i++)
        ans += get_left_val(x, y, i);
    for(int i = 0; i < d; i++)
        ans += get_right_val(x, y + 1, i);
    return ans;
} 



int main() {
    scanf("%d %d %d", &n, &m, &d);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &val[i][j]);
    //printf("\n");
    for(int i = 1; i <= n; i++) {
        int value = 0;
        for(int j = 1; j <= m; j++) {
            if(j == 1) {
                value = get_total(i, 1, d);
            }
            else {
                value = value 
                        + get_right_val(i, j, d) 
                        - get_left_val(i, j - 1, d);
            }
            //printf("%d ", value);
            if(value > max_val) {
                max_val = value;
                len = 1;
                ans[0].x = i;
                ans[0].y = j;
            }
            else if(value == max_val) {
                ans[len].x = i;
                ans[len].y = j;
                len++;
            }
        }
        //printf("\n");
    }
    printf("%d %d\n", max_val, len);
    for(int i = 0; i < len; i++)
        printf("%d %d\n", ans[i].x, ans[i].y);
    return 0;
}