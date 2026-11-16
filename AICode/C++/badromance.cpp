#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int k;
        scanf("%d", &k);
        vector<char> vis(n + 1, 0);
        vis[k] = 1;
        bool bad = false;
        int cyc = 0;
        vector<int> q;
        for (int nb : adj[k]) {
            if (vis[nb]) {
                bad = true;
                break;
            }
            q.clear();
            q.push_back(nb);
            vis[nb] = 1;
            long long V = 0, D = 0;
            for (size_t h = 0; h < q.size(); h++) {
                int u = q[h];
                V++;
                D += adj[u].size();
                for (int w : adj[u]) {
                    if (!vis[w]) {
                        vis[w] = 1;
                        q.push_back(w);
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
