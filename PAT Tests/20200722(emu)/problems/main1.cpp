#include <cstdio>

struct rational {
    long up;
    long down;
    rational(long u, long d) : up(u), down(d) {}
    rational() {}
};

long abs(long x) { return x < 0 ? (-x) : x; }

long gcd(long a, long b) {
    long r = abs(a) % abs(b);
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

rational simplify(rational r) {
    if (r.down == 0) {
        return r;
    } else {
        long d = gcd(r.up, r.down);
        return rational(r.up / d, r.down / d);
    }
}

rational sum(rational r1, rational r2) {
    return simplify(
        rational(r1.up * r2.down + r1.down * r2.up, r1.down * r2.down));
}

rational difference(rational r1, rational r2) {
    return simplify(
        rational(r1.up * r2.down - r1.down * r2.up, r1.down * r2.down));
}

rational product(rational r1, rational r2) {
    return simplify(rational(r1.up * r2.up, r1.down * r2.down));
}

rational quotient(rational r1, rational r2) {
    return simplify(rational(r1.up * r2.down, r1.down * r2.up));
}

void printSimpleRational(rational r) {
    if (r.down == 0) {
        printf("Inf");
        return;
    } else if (r.up == 0) {
        printf("0");
        return;
    }

    bool negative = (r.up < 0) != (r.down < 0);
    if (negative) printf("(-");

    r.up = abs(r.up);
    r.down = abs(r.down);
    long i = r.up / r.down;
    long res = r.up % r.down;
    if (res == 0)
        printf("%d", i);
    else if (i == 0)
        printf("%d/%d", r.up, r.down);
    else
        printf("%d %d/%d", i, res, r.down);

    if (negative) printf(")");
}

void printExpression(rational r1, rational r2, char op) {
    printSimpleRational(r1);
    printf(" %c ", op);
    printSimpleRational(r2);
    printf(" = ");
    rational result;
    switch (op) {
        case '+':
            result = sum(r1, r2);
            break;
        case '-':
            result = difference(r1, r2);
            break;
        case '*':
            result = product(r1, r2);
            break;
        case '/':
            result = quotient(r1, r2);
            break;
        default:
            break;
    }
    printSimpleRational(result);
    printf("\n");
}

int main(int argc, char const *argv[]) {
    long int x1, x2, y1, y2;
    scanf("%ld/%ld", &x1, &x2);
    scanf("%ld/%ld", &y1, &y2);
    rational r1 = simplify(rational(x1, x2));
    rational r2 = simplify(rational(y1, y2));
    printExpression(r1, r2, '+');
    printExpression(r1, r2, '-');
    printExpression(r1, r2, '*');
    printExpression(r1, r2, '/');
    return 0;
}
