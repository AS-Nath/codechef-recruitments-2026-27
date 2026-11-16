#include <stdio.h>

#define MAXN 200005

int par[MAXN], sz[MAXN];

int findp(int x) {
    while (par[x] != x) {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            int a = findp(u), b = findp(v);
            if (a != b) {
                ans += (long long)sz[a] * sz[b];
                if (sz[a] < sz[b]) {
                    int tmp = a;
                    a = b;
                    b = tmp;
                }
                par[b] = a;
                sz[a] += sz[b];
            }
            printf("%lld%c", ans, i + 1 < m ? ' ' : '\n');
        }
    }
    return 0;
}
