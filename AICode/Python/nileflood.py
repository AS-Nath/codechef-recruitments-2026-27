import sys
from collections import deque


def main():
    data = sys.stdin.buffer.read().split()
    n, m, q = int(data[0]), int(data[1]), int(data[2])
    w = [0] + [int(x) for x in data[3:3 + n]]
    g = [[] for _ in range(n + 1)]
    p = 3 + n
    for _ in range(m):
        u, v = int(data[p]), int(data[p + 1])
        p += 2
        g[u].append(v)
        g[v].append(u)
    INF = 10 ** 9
    out = []
    for _ in range(q):
        s, t = int(data[p]), int(data[p + 1])
        p += 2
        d = [INF] * (n + 1)
        d[s] = w[s]
        dq = deque([s])
        while dq:
            u = dq.popleft()
            du = d[u]
            for v in g[u]:
                nd = du + w[v]
                if nd < d[v]:
                    d[v] = nd
                    if w[v]:
                        dq.append(v)
                    else:
                        dq.appendleft(v)
        out.append(-1 if d[t] == INF else d[t])
    print("\n".join(map(str, out)))


main()
