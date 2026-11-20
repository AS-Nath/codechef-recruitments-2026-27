import sys
from collections import deque

def main():
    data = sys.stdin.buffer.read().split()
    pos = 0
    n = int(data[pos]); pos += 1
    m = int(data[pos]); pos += 1
    q = int(data[pos]); pos += 1
    wet = [0] * (n + 1)
    for i in range(1, n + 1):
        wet[i] = int(data[pos]); pos += 1
    adj = [[] for _ in range(n + 1)]
    for _ in range(m):
        u = int(data[pos]); v = int(data[pos + 1]); pos += 2
        adj[u].append(v)
        adj[v].append(u)

    INF = float("inf")
    out = []
    for _ in range(q):
        s = int(data[pos]); t = int(data[pos + 1]); pos += 2
        dist = [INF] * (n + 1)
        dist[s] = wet[s]
        dq = deque([s])
        while dq:
            u = dq.popleft()
            if u == t:
                break
            du = dist[u]
            for v in adj[u]:
                nd = du + wet[v]
                if nd < dist[v]:
                    dist[v] = nd
                    if wet[v] == 0:
                        dq.appendleft(v)
                    else:
                        dq.append(v)
        out.append(-1 if dist[t] == INF else dist[t])
    sys.stdout.write("\n".join(map(str, out)) + "\n")

main()