#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int left = 0;
    int right = static_cast<int>(s.size()) - 1;
    while (left < right) {
        while (left < right && !is_vowel(s[left])) {
            left += 1;
        }
        while (left < right && !is_vowel(s[right])) {
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
    cout << s << '\n';
    return 0;
}
