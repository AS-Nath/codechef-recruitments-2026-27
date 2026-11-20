#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    int *w = malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    int *head = malloc((n + 1) * sizeof(int));
    int *nxt = malloc(2 * m * sizeof(int));
    int *to = malloc(2 * m * sizeof(int));
    for (int i = 0; i <= n; i++) head[i] = -1;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;
        to[cnt] = u; nxt[cnt] = head[v]; head[v] = cnt++;
    }
    /* circular-free deque: each vertex can be pushed at most a few times,
       so use a buffer centred in a large array */
    int cap = 4 * (2 * m + n) + 16;
    int *dq = malloc(cap * sizeof(int));
    int *d = malloc((n + 1) * sizeof(int));
    while (q--) {
        int s, t;
        scanf("%d %d", &s, &t);
        for (int i = 0; i <= n; i++) d[i] = INF;
        int lo = cap / 2, hi = cap / 2; /* [lo, hi) */
        d[s] = w[s];
        dq[hi++] = s;
        while (lo < hi) {
            int u = dq[lo++];
            for (int e = head[u]; e != -1; e = nxt[e]) {
                int v = to[e];
                int nd = d[u] + w[v];
                if (nd < d[v]) {
                    d[v] = nd;
                    if (w[v]) dq[hi++] = v;
                    else dq[--lo] = v;
                }
            }
        }
        printf("%d\n", d[t] == INF ? -1 : d[t]);
    }
    return 0;
}
