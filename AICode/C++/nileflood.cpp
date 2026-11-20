#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    const int INF = 1e9;
    vector<int> d(n + 1);
    while (q--) {
        int s, t;
        scanf("%d %d", &s, &t);
        fill(d.begin(), d.end(), INF);
        deque<int> dq;
        d[s] = w[s];
        dq.push_back(s);
        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();
            for (int v : g[u]) {
                int nd = d[u] + w[v];
                if (nd < d[v]) {
                    d[v] = nd;
                    if (w[v]) dq.push_back(v);
                    else dq.push_front(v);
                }
            }
        }
        printf("%d\n", d[t] == INF ? -1 : d[t]);
    }
    return 0;
}
