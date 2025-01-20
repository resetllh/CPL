#include <stdio.h>
#include <stdbool.h>

static char *ones[] = {
  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
  "ten", "eleven", "twelve", "thirteen", "fourteen",
  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static char *tens[] = {
  "0", "1", "twenty", "thirty", "forty", 
  "fifty", "sixty", "seventy", "eighty", "ninety"};

void print_three(int n) {
    int h = n / 100;
    int rest = n % 100;
    int m = rest / 10;
    int l = n % 10;
    if(h == 0) {
        if(rest < 20) printf("%s", ones[rest]);
        else {
            printf("%s", tens[m]);
            if(l != 0) printf("-%s", ones[l]);
        }
    }
    else {
        printf("%s hundred", ones[h]);
        if(rest != 0) {
            printf(" and ");
            if(rest < 20) printf("%s", ones[rest]);
            else {
                printf("%s", tens[m]);
                if(l != 0) printf("-%s", ones[l]);
            }
        }
    }
}

void convert(int n) {
    if(n == -2147483648) {
        printf("minus two billion one hundred and forty-seven million four hundred and eighty-three thousand six hundred and forty-eight");
    }
    else if(n == 0) {
        printf("zero");
    }
    else {
        if(n < 0) {
            n = -n;
            printf("minus ");
        }
        int l1 = n % 1000;
        n = (n - l1) / 1000;
        int l2 = n % 1000;
        n = (n - l2) / 1000;
        int l3 = n % 1000;
        int l4 = (n - l3) / 1000;
        if(l4 != 0) {
            print_three(l4);
            printf(" billion ");
        }
        if(l3 != 0) {
            print_three(l3);
            printf(" million ");
        }
        if(l2 != 0) {
            print_three(l2);
            printf(" thousand ");
        }
        if(l1 != 0) {
            print_three(l1);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    convert(n);
    return 0;
}