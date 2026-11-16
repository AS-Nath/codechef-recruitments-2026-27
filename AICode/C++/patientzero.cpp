#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> par, sz;

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
        par.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        for (int i = 0; i <= n; i++) par[i] = i;
        long long ans = 0;
        string out;
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            int a = findp(u), b = findp(v);
            if (a != b) {
                ans += (long long)sz[a] * sz[b];
                if (sz[a] < sz[b]) swap(a, b);
                par[b] = a;
                sz[a] += sz[b];
            }
            out += to_string(ans);
            out += (i + 1 < m ? ' ' : '\n');
        }
        fputs(out.c_str(), stdout);
    }
    return 0;
}
