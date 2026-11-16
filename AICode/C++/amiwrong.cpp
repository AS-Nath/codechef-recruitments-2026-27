#include <iostream>
#include <string>
using namespace std;

long long parse(const string &s) {
    size_t i = 0;
    bool neg = false;
    if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
        neg = s[i] == '-';
        i++;
    }
    long long ip = 0;
    while (i < s.size() && isdigit(s[i])) ip = ip * 10 + (s[i++] - '0');
    long long fp = 0;
    int d = 0;
    if (i < s.size() && s[i] == '.') {
        i++;
        while (i < s.size() && isdigit(s[i]) && d < 3) {
            fp = fp * 10 + (s[i++] - '0');
            d++;
        }
    }
    while (d++ < 3) fp *= 10;
    long long v = ip * 1000 + fp;
    return neg ? -v : v;
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    cout << (parse(a) + parse(b) == parse(c) ? "YES" : "NO") << endl;
    return 0;
}
