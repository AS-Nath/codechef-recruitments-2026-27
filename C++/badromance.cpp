#include <bits/stdc++.h> 
using namespace std;

int main(void) {
    int T;
    cin >> T; 
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        vector<int> deg(n+1, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u] += 1;
            deg[v] += 1;
        }
        int K;
        cin >> K;
        /*
        We'll check if there are cycles in the graph (closed paths) or if it is like a tree, with no cycles. If it is like a tree,
        Then Chef will eventually reach some leaf node where Chefina can corner him. Otherwise, since Chef knows Chefina's next move, he'll just
        move safely around the cycle such that Chefina can't catch him forever. So if Chef starts on a cycle, it's a NO. And if he doesn't start on
        a cycle, even if they exist, it's a YES. This is because as per the problem we have to find a possible position for Chefina, and if Chef isn't
        already on a cycle we can find a start position for Chefina where he can corner Chef for sure.
        To do this, we'll evaluate the 2-core. This means removing all leaves, which may produce more leaves, and so on until there
        are no leaves left. Whatever graph is left is called the 2-core. It's called that because every vertex has a degree (number of
        edges connected to it) of 2 or higher. 
        So if Chef starts on the 2-core, he's won. Otherwise, he's lost. 
        */

        // We use BFS with a queue to 'peel' the leaves, leaving the 2-core behind.
        queue<int> q;
        vector<char> removed(n+1, 0);

        // Enqueue leaves and any isolated vertices where the degree is 0. 
        for (int i = 1; i <= n; ++i) {
            if (deg[i] <= 1) {
                q.push(i);
                removed[i] = 1; // mark as removed - it's not a part of a cycle. 
            }
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (removed[v]) {
                    continue;
                }
                deg[v] -= 1;
                if (deg[v] == 1) {
                    removed[v] = 1;
                    q.push(v);
                }
            }
        }
        // If K was removed, then K is not on a cycle. So Chefina can catch Chef.
        cout << (removed[K] ? "YES" : "NO") << '\n';
    }
    return 0;
}