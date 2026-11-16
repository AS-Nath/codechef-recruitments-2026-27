import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long k = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        HashSet<Long> seen = new HashSet<>();
        seen.add(0L);
        long sum = 0;
        boolean found = false;
        for (int i = 0; i < n; i++) {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            sum += Long.parseLong(st.nextToken());
            if (seen.contains(sum - k)) {
                found = true;
                break;
            }
            seen.add(sum);
        }
        System.out.println(found ? "YES" : "NO");
    }
}
