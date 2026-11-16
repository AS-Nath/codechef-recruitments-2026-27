import java.io.*;
import java.util.*;

public class Solution {
    static int[] par, sz;

    static int find(int x) {
        while (par[x] != x) {
            par[x] = par[par[x]];
            x = par[x];
        }
        return x;
    }

    public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(new BufferedInputStream(System.in));
        st.nextToken();
        int t = (int) st.nval;
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            st.nextToken();
            int n = (int) st.nval;
            st.nextToken();
            int m = (int) st.nval;
            par = new int[n + 1];
            sz = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                par[i] = i;
                sz[i] = 1;
            }
            long ans = 0;
            for (int i = 0; i < m; i++) {
                st.nextToken();
                int u = (int) st.nval;
                st.nextToken();
                int v = (int) st.nval;
                int a = find(u), b = find(v);
                if (a != b) {
                    ans += (long) sz[a] * sz[b];
                    if (sz[a] < sz[b]) {
                        int tmp = a;
                        a = b;
                        b = tmp;
                    }
                    par[b] = a;
                    sz[a] += sz[b];
                }
                sb.append(ans).append(i + 1 < m ? ' ' : '\n');
            }
        }
        System.out.print(sb);
    }
}
