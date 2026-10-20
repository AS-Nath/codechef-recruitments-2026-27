import sys

data = sys.stdin.buffer.read().split()
pos = 0
t = int(data[pos]); pos += 1
out = []
for _ in range(t):
    n = int(data[pos]); m = int(data[pos + 1]); pos += 2
    parent = list(range(n + 1))
    size = [1] * (n + 1)
    pairs = 0
    res = []
    for _ in range(m):
        u = int(data[pos]); v = int(data[pos + 1]); pos += 2
        while parent[u] != u:
            parent[u] = parent[parent[u]]
            u = parent[u]
        while parent[v] != v:
            parent[v] = parent[parent[v]]
            v = parent[v]
        if u != v:
            if size[u] < size[v]:
                u, v = v, u
            pairs += size[u] * size[v]
            parent[v] = u
            size[u] += size[v]
        res.append(pairs)
    out.append(" ".join(map(str, res)))
sys.stdout.write("\n".join(out) + "\n")