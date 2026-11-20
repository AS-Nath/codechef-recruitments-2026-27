#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> wet(n + 1);
    for (int i = 1; i <= n; i += 1) {
        cin >> wet[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i += 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while (q--) {
        int s, t;
        cin >> s >> t;
        vector<int> dist(n + 1, INT_MAX);
        deque<int> dq;
        dist[s] = wet[s];
        dq.push_front(s);
        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();
            for (int v : adj[u]) {
                int nd = dist[u] + wet[v];
                if (nd < dist[v]) {
                    dist[v] = nd;
                    if (wet[v] == 0) {
                        dq.push_front(v);
                    } else {
                        dq.push_back(v);
                    }
                }
            }
        }
        cout << (dist[t] == INT_MAX ? -1 : dist[t]) << '\n';
    }
    return 0;
}
