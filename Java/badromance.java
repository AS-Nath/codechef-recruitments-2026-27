import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            List<List<Integer>> adj = new ArrayList<>();
            for (int i = 0; i <= n; i++) {
                adj.add(new ArrayList<>());
            }
            int[] deg = new int[n + 1];
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                adj.get(u).add(v);
                adj.get(v).add(u);
                deg[u]++;
                deg[v]++;
            }
            int K = Integer.parseInt(br.readLine().trim());
            Queue<Integer> q = new ArrayDeque<>();
            boolean[] removed = new boolean[n + 1];
            for (int i = 1; i <= n; i++) {
                if (deg[i] <= 1) {
                    q.offer(i);
                    removed[i] = true;
                }
            }
            while (!q.isEmpty()) {
                int u = q.poll();
                for (int v : adj.get(u)) {
                    if (removed[v]) {
                        continue;
                    }
                    deg[v]--;
                    if (deg[v] == 1) {
                        removed[v] = true;
                        q.offer(v);
                    }
                }
            }
            out.append(removed[K] ? "YES" : "NO").append('\n');
        }
        System.out.print(out);
    }
}
