#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct _BigInt
{
    int bit[1200];
} BigInt;

BigInt zero = {};
BigInt one = (BigInt){.bit[0] = 1};

BigInt readBigInt() {
    BigInt bigInt = zero;
    char buf[10005];
    scanf("%s", buf);
    int len = strlen(buf);
    for (int i = 0; i < len; i++) {
        bigInt.bit[i / 9] += (buf[len - 1 -i] - '0') * pow(10, i % 9);
    }
    return bigInt;
}

void writeBigInt(BigInt bigInt) {
    int i = 0;
    for(i = 1199; i > 0; i--) {
        if(bigInt.bit[i] != 0) break;
    }
    printf("%d", bigInt.bit[i]);
    for(i--; i >= 0; i--) {
        printf("%09d", bigInt.bit[i]);
    }
    putchar('\n');
}

BigInt add(BigInt a, BigInt b) {
    BigInt sum = zero;
    int carry = 0;
    for(int i = 0; i < 1200; i++) {
        int temp = a.bit[i] + b.bit[i] + carry;
        carry = temp / 1000000000;
        sum.bit[i] = temp - 1000000000 * carry;
    }
    return sum;
}

BigInt sub(BigInt a, BigInt b) {
    BigInt diff = zero;
    int carry = 0;
    for(int i = 0; i < 1200; i++) {
        int temp = a.bit[i] - b.bit[i] - carry;
        carry = temp < 0 ? 1: 0;
        diff.bit[i] = temp + 1000000000 * carry;
    }
    return diff;
}

BigInt div2(BigInt a) {
    BigInt ret = zero;
    int carry = 0;
    for(int i = 24; i >= 0; i--) {
        int old_carry = carry;
        carry = a.bit[i] & 1;
        ret.bit[i] = (a.bit[i] + 1000000000 * old_carry) / 2;
    }
    return ret;
}

bool geq(BigInt a, BigInt b) {
    for(int i = 24; i >= 0; i--) {
        if(a.bit[i] == b.bit[i]) continue;
        if(a.bit[i] > b.bit[i]) return true;
        else return false;
    }
    return true;
}

bool eq(BigInt a, BigInt b) {
    for(int i = 24; i >= 0; i--) {
        if(a.bit[i] != b.bit[i]) return false;
    }
    return true;
}

BigInt mul(BigInt a, BigInt b) {
    BigInt prod = zero;
    while(!(eq(a, zero))) {
        if(a.bit[0] & 1) {
            prod = add(prod, b);
        }
        b = add(b, b);
        a = div2(a);
    }
    return prod;
}

BigInt idiv(BigInt a, BigInt b) {
    BigInt quot = zero;
    BigInt pow = b;
    BigInt pow2 = one;
    int cnt = 0;
    while (geq(a, pow))
    {
        cnt++;
        pow = add(pow, pow);
        pow2 = add(pow2, pow2);
    }
    while(cnt--) {
        pow = div2(pow);
        pow2 = div2(pow2);
        if(geq(a, pow)) {
            quot = add(quot, pow2);
            a = sub(a, pow);
        }
    }
    return quot;
}

int main() {
    int n;
    char op;
    scanf("%d", &n);
    while(n--) {
        BigInt a, b, c;
        c = zero;
        a = readBigInt();
        scanf(" %c", &op);
        b = readBigInt();
        switch(op) {
            case '+': c = add(a, b);break;
            case '-': c = sub(a, b);break;
            case '*': c = mul(a, b);break;
            case '/': c = idiv(a, b);break;
            default: break;
        }
        writeBigInt(c);
    }
    return 0;
}