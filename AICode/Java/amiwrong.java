import java.io.*;
import java.math.BigDecimal;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        BigDecimal a = new BigDecimal(st.nextToken());
        BigDecimal b = new BigDecimal(st.nextToken());
        BigDecimal c = new BigDecimal(st.nextToken());
        System.out.println(a.add(b).compareTo(c) == 0 ? "YES" : "NO");
    }
}
