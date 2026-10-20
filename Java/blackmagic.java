import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {
    static boolean isVowel(char c) {
        return "aeiouAEIOU".indexOf(c) != -1;
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] s = br.readLine().toCharArray();
        int left = 0;
        int right = s.length - 1;
        while (left < right) {
            while (left < right && !isVowel(s[left])) {
                left += 1;
            }
            while (left < right && !isVowel(s[right])) {
                right -= 1;
            }
            if (left < right) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left += 1;
                right -= 1;
            }
        }
        System.out.println(s);
    }
}
