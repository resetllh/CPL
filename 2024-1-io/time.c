#include <stdio.h>

int main() {
    char month[20], week[20];
    int day, year, hour, minute, second, mm, dd, hh, ss, yyyy;
    scanf("%s %d %d %s %d %d %d", month, &day, &year, week, &hour, &minute, &second);
    
    char www[20] = {week[0], week[1], week[2], '\0'};
    char mmm[20] = {month[0], month[1], month[2], '\0'};

    printf("%s %s %.2d %.2d:%.2d:%.2d %.4d", www, mmm, day, hour, minute, second, year);
    return 0;
}