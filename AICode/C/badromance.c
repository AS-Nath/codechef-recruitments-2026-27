#include <stdio.h>
#include <string.h>

#define MAXN 200005
#define MAXM 400010

int head[MAXN], nxt[MAXM], to[MAXM], deg[MAXN], q[MAXN];
char vis[MAXN];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= n; i++) {
            head[i] = -1;
            deg[i] = 0;
            vis[i] = 0;
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;
            to[cnt] = u; nxt[cnt] = head[v]; head[v] = cnt++;
            deg[u]++;
            deg[v]++;
        }
        int k;
        scanf("%d", &k);
        vis[k] = 1;
        int bad = 0, cyc = 0;
        for (int e = head[k]; e != -1 && !bad; e = nxt[e]) {
            int nb = to[e];
            if (vis[nb]) {
                bad = 1;
                break;
            }
            int qh = 0, qt = 0;
            q[qt++] = nb;
            vis[nb] = 1;
            long long V = 0, D = 0;
            while (qh < qt) {
                int u = q[qh++];
                V++;
                D += deg[u];
                for (int f = head[u]; f != -1; f = nxt[f]) {
                    int w = to[f];
                    if (!vis[w]) {
                        vis[w] = 1;
                        q[qt++] = w;
                    }
                }
            }
            long long E = (D - 1) / 2;
            if (E >= V) cyc++;
        }
        puts(!bad && cyc <= 1 ? "YES" : "NO");
    }
    return 0;
}
