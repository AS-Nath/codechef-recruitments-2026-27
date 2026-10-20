import java.io.*;
import java.util.*;

public class Solution {
    static int[] parent, size;
    static int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; 
            x = parent[x];
        }
        return x;
    }
    static DataInputStream in;
    static byte[] buf = new byte[1 << 16];
    static int bufLen = 0, bufPtr = 0;
    static int readByte() throws IOException {
        if (bufPtr == bufLen) {
            bufLen = in.read(buf, 0, buf.length);
            bufPtr = 0;
            if (bufLen <= 0) return -1;
        }
        return buf[bufPtr++];
    }
    static int nextInt() throws IOException {
        int c = readByte();
        while (c != '-' && (c < '0' || c > '9')) c = readByte();
        boolean neg = false;
        if (c == '-') {
            neg = true;
            c = readByte();
        }
        int res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + (c - '0');
            c = readByte();
        }
        return neg ? -res : res;
    }
    public static void main(String[] args) throws IOException {
        in = new DataInputStream(new BufferedInputStream(System.in, 1 << 16));
        StringBuilder sb = new StringBuilder();
        int t = nextInt();
        while (t-- > 0) {
            int n = nextInt(), m = nextInt();
            parent = new int[n + 1];
            size = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
            long pairs = 0; 
            for (int i = 0; i < m; i++) {
                int u = nextInt(), v = nextInt();
                int a = find(u), b = find(v);
                if (a != b) {
                    if (size[a] < size[b]) {
                        int tmp = a;
                        a = b;
                        b = tmp;
                    }
                    pairs += (long) size[a] * size[b];
                    parent[b] = a;
                    size[a] += size[b];
                }
                sb.append(pairs).append(i + 1 < m ? ' ' : '\n');
            }
        }
        System.out.print(sb);
    }
}