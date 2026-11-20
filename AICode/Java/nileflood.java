import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(new BufferedInputStream(System.in));
        st.nextToken();
        int n = (int) st.nval;
        st.nextToken();
        int m = (int) st.nval;
        st.nextToken();
        int q = (int) st.nval;
        int[] w = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            st.nextToken();
            w[i] = (int) st.nval;
        }
        int[] head = new int[n + 1];
        Arrays.fill(head, -1);
        int[] nxt = new int[2 * m];
        int[] to = new int[2 * m];
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            st.nextToken();
            int u = (int) st.nval;
            st.nextToken();
            int v = (int) st.nval;
            to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;
            to[cnt] = u; nxt[cnt] = head[v]; head[v] = cnt++;
        }
        final int INF = 1_000_000_000;
        int[] d = new int[n + 1];
        StringBuilder sb = new StringBuilder();
        ArrayDeque<Integer> dq = new ArrayDeque<>();
        while (q-- > 0) {
            st.nextToken();
            int s = (int) st.nval;
            st.nextToken();
            int t = (int) st.nval;
            Arrays.fill(d, INF);
            d[s] = w[s];
            dq.clear();
            dq.addFirst(s);
            while (!dq.isEmpty()) {
                int u = dq.pollFirst();
                for (int e = head[u]; e != -1; e = nxt[e]) {
                    int v = to[e];
                    int nd = d[u] + w[v];
                    if (nd < d[v]) {
                        d[v] = nd;
                        if (w[v] == 1) dq.addLast(v);
                        else dq.addFirst(v);
                    }
                }
            }
            sb.append(d[t] == INF ? -1 : d[t]).append('\n');
        }
        System.out.print(sb);
    }
}
