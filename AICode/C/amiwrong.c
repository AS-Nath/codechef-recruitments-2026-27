#include <stdio.h>
#include <string.h>

long long parse(const char *s) {
    int neg = 0;
    if (*s == '-') { neg = 1; s++; }
    else if (*s == '+') s++;
    long long ip = 0;
    while (*s >= '0' && *s <= '9') {
        ip = ip * 10 + (*s - '0');
        s++;
    }
    long long fp = 0;
    int d = 0;
    if (*s == '.') {
        s++;
        while (*s >= '0' && *s <= '9' && d < 3) {
            fp = fp * 10 + (*s - '0');
            d++;
            s++;
        }
    }
    while (d < 3) {
        fp *= 10;
        d++;
    }
    long long v = ip * 1000 + fp;
    return neg ? -v : v;
}

int main() {
    char a[64], b[64], c[64];
    scanf("%63s %63s %63s", a, b, c);
    puts(parse(a) + parse(b) == parse(c) ? "YES" : "NO");
    return 0;
}
