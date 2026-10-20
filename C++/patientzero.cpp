#include <bits/stdc++.h>
using namespace std;

static vector<int> parent_, sz_;

static int find(int x) {
    while (parent_[x] != x) {
        parent_[x] = parent_[parent_[x]];
        x = parent_[x];
    }
    return x;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        parent_.assign(n + 1, 0);
        sz_.assign(n + 1, 1);
        for (int i = 0; i <= n; i++) parent_[i] = i;
        long long pairs = 0;  
        string out;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            int a = find(u), b = find(v);
            if (a != b) {
                if (sz_[a] < sz_[b]) swap(a, b);
                pairs += (long long)sz_[a] * sz_[b];
                parent_[b] = a;
                sz_[a] += sz_[b];
            }
            out += to_string(pairs);
            out += (i + 1 < m ? ' ' : '\n');
        }
        cout << out;
    }
    return 0;
}