#include <stdio.h>
#include <stdbool.h>

typedef struct memory
{
    int id;
    int size;
    int next;
} memory;

memory mmr[100000];
int head;
int pos;

void init(int n) {
    mmr[0].id = 0;
    mmr[0].size = n;
    mmr[0].next = -1;
    head = 0;
    pos = 1;
}

int get_length() {
    int p = head;
    int len = 0;
    while(p != -1) {
        len++;
        p = mmr[p].next;
    }
    return len;
}

void Query() {
    int len = get_length();
    printf("%d\n", len);
    int p = head;
    while(p != -1) {
        printf("%d ", mmr[p].id);
        p = mmr[p].next;
    }
    printf("\n");
}

bool insert_exist(int id, int exp) {
    int p = head;
    while(p != -1) {
        if(mmr[p].size == exp && mmr[p].id == 0) {
            mmr[p].id = id;
            return true;
        }
        p = mmr[p].next;
    }
    return false;
}

void split(int exp) {
    int p = head;
    while(p != -1) {
        if(mmr[p].id == 0 && mmr[p].size > exp) break;
        p = mmr[p].next;
    }
    //printf("now p = %d\n", p);
    int new_p = pos;
    pos++;
    mmr[new_p].id = 0;
    mmr[new_p].size = mmr[p].size - 1;
    mmr[new_p].next = mmr[p].next;
    mmr[p].next = new_p;
    mmr[p].size = mmr[p].size - 1;
}

void insert(int id, int m) {
    int exp = 0, s = 1;
    while(m > s) {
        s = s * 2;
        exp += 1;
    }
    //printf("exp = %d\n", exp);
    while(!insert_exist(id, exp)) {
        split(exp);
       // printf("Query\n");
       // Query();
       // printf("End\n");
    }
}


int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    init(n);
    while(q--) {
        char ops[10];
        scanf("%s", ops);
        if(ops[0] == 'Q') {
            Query();
        }
        else {
            int id, m;
            scanf("%d %d", &id, &m);
            insert(id, m);
        }
    }
    return 0;
}