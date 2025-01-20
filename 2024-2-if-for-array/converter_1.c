#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int h, m, l;
    h = n / 100;
    l = n % 10;
    m = (n - h * 100) / 10;
    
    switch (h)
    {
    case 9:
        printf("nine hundred");
        break;
    case 8:
        printf("eight hundred");
        break;
    case 7:
        printf("seven hundred");
        break;
    case 6:
        printf("six hundred");
        break;
    case 5:
        printf("five hundred");
        break;
    case 4:
        printf("four hundred");
        break;
    case 3:
        printf("three hundred");
        break;
    case 2:
        printf("two hundred");
        break;
    case 1:
        printf("one hundred");
        break;
    }
    if(m != 0 || l != 0) {
        if(h != 0) {
            printf(" and ");
        }
        if(m >= 2) {
            switch (m)
            {
            case 9:
                printf("ninety");
                break;
            case 8:
                printf("eighty");
                break;
            case 7:
                printf("seventy");
                break;
            case 6:
                printf("sixty");
                break;
            case 5:
                printf("fifty");
                break;
            case 4:
                printf("forty");
                break;
            case 3:
                printf("thirty");
                break;
            case 2:
                printf("twenty");
                break;
            }

            switch (l)
            {
            case 9:
                printf("-nine");
                break;
            case 8:
                printf("-eight");
                break;
            case 7:
                printf("-seven");
                break;
            case 6:
                printf("-six");
                break;
            case 5:
                printf("-five");
                break;
            case 4:
                printf("-four");
                break;
            case 3:
                printf("-three");
                break;
            case 2:
                printf("-two");
                break;
            case 1:
                printf("-one");
                break;
            }
        }
        else if(m == 0) {
            switch (l)
            {
            case 9:
                printf("nine");
                break;
            case 8:
                printf("eight");
                break;
            case 7:
                printf("seven");
                break;
            case 6:
                printf("six");
                break;
            case 5:
                printf("five");
                break;
            case 4:
                printf("four");
                break;
            case 3:
                printf("three");
                break;
            case 2:
                printf("two");
                break;
            case 1:
                printf("one");
                break;
            }
        }
        else {
            switch (l)
            {
            case 9:
                printf("nineteen");
                break;
            case 8:
                printf("eighteen");
                break;
            case 7:
                printf("seventeen");
                break;
            case 6:
                printf("sixteen");
                break;
            case 5:
                printf("fifteen");
                break;
            case 4:
                printf("fourteen");
                break;
            case 3:
                printf("thirteen");
                break;
            case 2:
                printf("twelve");
                break;
            case 1:
                printf("eleven");
                break;
            case 0:
                printf("ten");
                break;
            }
        }
    }
    if(h == 0 && m == 0 && l == 0) printf("zero");
    return 0;
}