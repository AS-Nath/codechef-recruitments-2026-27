import sys

def main():
    data = sys.stdin.buffer.read().split()
    pos = 0
    t = int(data[pos]); pos += 1
    out = []
    for _ in range(t):
        n = int(data[pos]); m = int(data[pos + 1]); pos += 2
        adj = [[] for _ in range(n + 1)]
        for _ in range(m):
            u = int(data[pos]); v = int(data[pos + 1]); pos += 2
            adj[u].append(v)
            adj[v].append(u)
        k = int(data[pos]); pos += 1
        vis = [False] * (n + 1)
        vis[k] = True
        bad = False
        cyc = 0
        for nb in adj[k]:
            if vis[nb]:
                bad = True
                break
            vis[nb] = True
            stack = [nb]
            V = 0
            D = 0
            while stack:
                u = stack.pop()
                V += 1
                D += len(adj[u])
                for w in adj[u]:
                    if not vis[w]:
                        vis[w] = True
                        stack.append(w)
            if (D - 1) // 2 >= V:
                cyc += 1
        out.append("YES" if not bad and cyc <= 1 else "NO")
    print("\n".join(out))

main()
