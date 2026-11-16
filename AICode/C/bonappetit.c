#include <stdio.h>
#include <stdlib.h>

#define SZ (1 << 19)

long long keys[SZ];
char used[SZ];

unsigned int hsh(long long x) {
    unsigned long long h = (unsigned long long)x * 11400714819323198485ULL;
    return (unsigned int)(h >> 45) & (SZ - 1);
}

int has(long long x) {
    unsigned int i = hsh(x);
    while (used[i]) {
        if (keys[i] == x) return 1;
        i = (i + 1) & (SZ - 1);
    }
    return 0;
}

void add(long long x) {
    unsigned int i = hsh(x);
    while (used[i]) {
        if (keys[i] == x) return;
        i = (i + 1) & (SZ - 1);
    }
    used[i] = 1;
    keys[i] = x;
}

int main() {
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    long long sum = 0;
    add(0);
    int found = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        scanf("%lld", &a);
        sum += a;
        if (has(sum - k)) found = 1;
        add(sum);
    }
    printf(found ? "YES" : "NO");
    return 0;
}
