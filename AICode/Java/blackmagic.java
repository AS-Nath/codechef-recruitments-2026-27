import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {
    static boolean isVowel(char c) {
        return "aeiouAEIOU".indexOf(c) != -1;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] s = br.readLine().trim().toCharArray();
        int i = 0, j = s.length - 1;
        while (i < j) {
            while (i < j && !isVowel(s[i])) i++;
            while (i < j && !isVowel(s[j])) j--;
            if (i < j) {
                char t = s[i];
                s[i] = s[j];
                s[j] = t;
                i++;
                j--;
            }
        }
        System.out.println(new String(s));
    }
}
