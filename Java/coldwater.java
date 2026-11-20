import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        in.nextToken();
        int n = (int) in.nval;
        in.nextToken();
        int m = (int) in.nval;
        in.nextToken();
        int q = (int) in.nval;
        int[] wet = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            in.nextToken();
            wet[i] = (int) in.nval;
        }
        int[] head = new int[n + 1];
        Arrays.fill(head, -1);
        int[] next = new int[2 * m];
        int[] to = new int[2 * m];
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            in.nextToken();
            int u = (int) in.nval;
            in.nextToken();
            int v = (int) in.nval;
            to[cnt] = v;
            next[cnt] = head[u];
            head[u] = cnt++;
            to[cnt] = u;
            next[cnt] = head[v];
            head[v] = cnt++;
        }
        final int INF = Integer.MAX_VALUE;
        int[] dist = new int[n + 1];
        StringBuilder sb = new StringBuilder();
        while (q-- > 0) {
            in.nextToken();
            int s = (int) in.nval;
            in.nextToken();
            int t = (int) in.nval;
            Arrays.fill(dist, INF);
            ArrayDeque<Integer> dq = new ArrayDeque<>();
            dist[s] = wet[s];
            dq.addLast(s);
            while (!dq.isEmpty()) {
                int u = dq.pollFirst();
                for (int e = head[u]; e != -1; e = next[e]) {
                    int v = to[e];
                    int nd = dist[u] + wet[v];
                    if (nd < dist[v]) {
                        dist[v] = nd;
                        if (wet[v] == 0) {
                            dq.addFirst(v);
                        } else {
                            dq.addLast(v);
                        }
                    }
                }
            }
            sb.append(dist[t] == INF ? -1 : dist[t]).append("\n");
        }
        System.out.print(sb);
    }
}