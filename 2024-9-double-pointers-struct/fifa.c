#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct people{
    char name[25];
    int at;
    int df;
    int cm;
} peo;

typedef struct team{
    char team_name[25];
    peo p[11];
} team;

team t[1005];

int compare_at(const void * p1,const void * p2) {
    team* q1 = (team*)p1;
    team* q2 = (team*)p2;
    int q1_sum_score = 0;
    int q2_sum_score = 0;
    for(int i = 0; i < 11; i++) {
        q1_sum_score += q1->p[i].at;
        q2_sum_score += q2->p[i].at;
    }
    return q2_sum_score - q1_sum_score;
}

int compare_df(const void * p1,const void * p2) {
    team* q1 = (team*)p1;
    team* q2 = (team*)p2;
    int q1_sum_score = 0;
    int q2_sum_score = 0;
    for(int i = 0; i < 11; i++) {
        q1_sum_score += q1->p[i].df;
        q2_sum_score += q2->p[i].df;
    }
    return q2_sum_score - q1_sum_score;
}

int compare_cm(const void * p1,const void * p2) {
    team* q1 = (team*)p1;
    team* q2 = (team*)p2;
    int q1_sum_score = 0;
    int q2_sum_score = 0;
    for(int i = 0; i < 11; i++) {
        q1_sum_score += q1->p[i].cm;
        q2_sum_score += q2->p[i].cm;
    }
    return q2_sum_score - q1_sum_score;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", t[i].team_name);
        for(int j = 0; j < 11; j++) {
            scanf("%s", t[i].p[j].name);
            scanf("%d", &t[i].p[j].at);
            scanf("%d", &t[i].p[j].df);
            scanf("%d", &t[i].p[j].cm);
        }
    }
    qsort(t, n, sizeof(t[0]), compare_at);
    for(int i = 0; i < n; i++)
        printf("%s ", t[i].team_name);
    printf("\n");
    qsort(t, n, sizeof(t[0]), compare_df);
    for(int i = 0; i < n; i++)
        printf("%s ", t[i].team_name);
    printf("\n");
    qsort(t, n, sizeof(t[0]), compare_cm);
    for(int i = 0; i < n; i++)
        printf("%s ", t[i].team_name);
    return 0;
}