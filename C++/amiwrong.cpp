#include <bits/stdc++.h>
using namespace std;

int main(void) {
    double a;
    double b;
    double c;
    cin >> a >> b >> c; 
    if (round((a + b) * 1000) / 1000.0 == c) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n"; 
    }
    return 0;
}
