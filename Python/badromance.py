from collections import deque
import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n, m = map(int, input().split())
    adj = [[] for _ in range(n + 1)]
    deg = [0] * (n + 1)
    for _ in range(m):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
        deg[u] += 1
        deg[v] += 1
    K = int(input())
    q = deque()
    removed = [False] * (n + 1)
    for i in range(1, n + 1):
        if deg[i] <= 1:
            q.append(i)
            removed[i] = True
    while q:
        u = q.popleft()
        for v in adj[u]:
            if removed[v]:
                continue
            deg[v] -= 1

            if deg[v] == 1:
                removed[v] = True
                q.append(v)
    print("YES" if removed[K] else "NO")