#include <stdio.h>
int f(int n, int k) {
    if(n == 1) return 1;
    else {
        int id = k % n;
        if(id == 0) id += n;
        int ans = f(n - 1, k);
        if(ans <= n - id) return ans + id;
        else return ans + id - n;
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", f(n, k));
    return 0;
}