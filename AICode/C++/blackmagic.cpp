#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isV(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string s;
    cin >> s;
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        while (i < j && !isV(s[i])) i++;
        while (i < j && !isV(s[j])) j--;
        if (i < j) swap(s[i++], s[j--]);
    }
    cout << s << endl;
    return 0;
}
