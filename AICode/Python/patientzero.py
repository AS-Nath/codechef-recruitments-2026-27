import sys

def main():
    data = sys.stdin.buffer.read().split()
    pos = 0
    t = int(data[pos]); pos += 1
    out = []
    for _ in range(t):
        n = int(data[pos]); m = int(data[pos + 1]); pos += 2
        par = list(range(n + 1))
        sz = [1] * (n + 1)
        ans = 0
        res = []
        for _ in range(m):
            u = int(data[pos]); v = int(data[pos + 1]); pos += 2
            while par[u] != u:
                par[u] = par[par[u]]
                u = par[u]
            while par[v] != v:
                par[v] = par[par[v]]
                v = par[v]
            if u != v:
                ans += sz[u] * sz[v]
                if sz[u] < sz[v]:
                    u, v = v, u
                par[v] = u
                sz[u] += sz[v]
            res.append(ans)
        out.append(" ".join(map(str, res)))
    print("\n".join(out))

main()
