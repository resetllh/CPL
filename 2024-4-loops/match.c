#include <stdio.h>
#include <stdbool.h>

int a[505][505] = {0};
typedef struct Pos
{
    bool flag;
    int i1;
    int j1;
    int i2;
    int j2;
} pos;
pos number[125005];
int n;
int m;

bool check_ri(int i1, int j1, int i2, int j2) {
    bool flag = true;
    for(int j = j1 + 1; j < m; j++) if(a[i1][j] != 0) {
        flag = false;
        break;
    }
    for(int j = j2 + 1; j < m; j++) if(a[i2][j] != 0) {
        flag = false;
        break;
    }
    return flag;
}

bool check_le(int i1, int j1, int i2, int j2) {
    bool flag = true;
    for(int j = j1 - 1; j >= 0; j--) if(a[i1][j] != 0) {
        flag = false;
        break;
    }
    for(int j = j2 - 1; j >= 0; j--) if(a[i2][j] != 0) {
        flag = false;
        break;
    }
    return flag;
}

bool check_lo(int i1, int j1, int i2, int j2) {
    bool flag = true;
    for(int i = i1 + 1; i < n; i++) if(a[i][j1] != 0) {
        flag = false;
        break;
    }
    for(int i = i2 + 1; i < n; i++) if(a[i][j2] != 0) {
        flag = false;
        break;
    }
    return flag;
}

bool check_hi(int i1, int j1, int i2, int j2) {
    bool flag = true;
    for(int i = i1 - 1; i >= 0; i--) if(a[i][j1] != 0) {
        flag = false;
        break;
    }
    for(int i = i2 - 1; i >= 0; i--) if(a[i][j2] != 0) {
        flag = false;
        break;
    }
    return flag;
}

bool check(int i1, int j1, int i2, int j2) {
    if( check_hi(i1, j1, i2, j2) || 
        check_lo(i1, j1, i2, j2) || 
        check_le(i1, j1, i2, j2) || 
        check_ri(i1, j1, i2, j2) ) return true;
    else return false;
}

void operation(int id, int i1, int j1, int i2, int j2) {
    if(check(i1, j1, i2, j2)) {
        a[i1][j1] = a[i2][j2] = 0;
        printf("%d ", id);
    }
} 

int main() {
    scanf("%d %d", &n ,&m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            int num = a[i][j];
            if(number[num].flag) {
                number[num].i2 = i;
                number[num].j2 = j;
            }
            else {
                number[num].flag = true;
                number[num].i1 = i;
                number[num].j1 = j;
            }
        }
    }
    for(int id = 1; id < 125005; id++) {
        if(number[id].flag) {
            int i1 = number[id].i1;
            int j1 = number[id].j1;
            int i2 = number[id].i2;
            int j2 = number[id].j2;
            operation(id, i1, j1, i2, j2);
        }
    }
    return 0;
}