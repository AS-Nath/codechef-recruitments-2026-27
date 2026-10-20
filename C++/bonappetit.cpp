#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long int k;
    cin >> n >> k;
    unordered_set<long long int> prefix_sums;
    prefix_sums.insert(0);
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        long long int x;
        cin >> x;
        sum += x;
        if (prefix_sums.count(sum - k)) {
            cout << "YES\n";
            return 0;
        }
        prefix_sums.insert(sum);
    }
    cout << "NO\n";
    return 0;
}
