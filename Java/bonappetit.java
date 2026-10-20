
import java.io.*;
import java.util.HashSet;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] first = br.readLine().trim().split("\\s+");
        int n = Integer.parseInt(first[0]);
        long k = Long.parseLong(first[1]);
        String[] values = br.readLine().trim().split("\\s+");
        HashSet<Long> prefixSums = new HashSet<>();
        prefixSums.add(0L);
        long sum = 0;
        for (int i = 0; i < n; i += 1) {
            long x = Long.parseLong(values[i]);
            sum += x;
            if (prefixSums.contains(sum - k)) {
                System.out.println("YES");
                return;
            }
            prefixSums.add(sum);
        }
        System.out.println("NO");
    }
}
