import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        DataInputStream in = new DataInputStream(new BufferedInputStream(System.in, 1 << 16));
        int t = nextInt(in);
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            int n = nextInt(in), m = nextInt(in);
            int[] head = new int[n + 1];
            Arrays.fill(head, -1);
            int[] nxt = new int[2 * m];
            int[] to = new int[2 * m];
            int[] deg = new int[n + 1];
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                int u = nextInt(in), v = nextInt(in);
                to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;
                to[cnt] = u; nxt[cnt] = head[v]; head[v] = cnt++;
                deg[u]++;
                deg[v]++;
            }
            int k = nextInt(in);
            boolean[] vis = new boolean[n + 1];
            vis[k] = true;
            boolean bad = false;
            int cyc = 0;
            int[] q = new int[n + 1];
            for (int e = head[k]; e != -1 && !bad; e = nxt[e]) {
                int nb = to[e];
                if (vis[nb]) {
                    bad = true;
                    break;
                }
                int qh = 0, qt = 0;
                q[qt++] = nb;
                vis[nb] = true;
                long V = 0, D = 0;
                while (qh < qt) {
                    int u = q[qh++];
                    V++;
                    D += deg[u];
                    for (int f = head[u]; f != -1; f = nxt[f]) {
                        int w = to[f];
                        if (!vis[w]) {
                            vis[w] = true;
                            q[qt++] = w;
                        }
                    }
                }
                long E = (D - 1) / 2;
                if (E >= V) cyc++;
            }
            sb.append(!bad && cyc <= 1 ? "YES" : "NO").append('\n');
        }
        System.out.print(sb);
    }

    private static int nextInt(DataInputStream in) throws IOException {
        int ret = 0;
        int b = in.read();
        while (b < '0') b = in.read();
        while (b >= '0') {
            ret = ret * 10 + (b - '0');
            b = in.read();
        }
        return ret;
    }
}
