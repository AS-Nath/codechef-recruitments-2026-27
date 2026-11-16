#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    vector<long long> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        long long a;
        scanf("%lld", &a);
        p[i] = p[i - 1] + a;
    }
    vector<long long> s(p);
    sort(s.begin(), s.end());
    vector<int> first(n + 1, n + 1);
    for (int i = n; i >= 0; i--) {
        int idx = lower_bound(s.begin(), s.end(), p[i]) - s.begin();
        first[idx] = i;
    }
    bool found = false;
    for (int j = 1; j <= n && !found; j++) {
        long long need = p[j] - k;
        auto it = lower_bound(s.begin(), s.end(), need);
        if (it != s.end() && *it == need) {
            int idx = it - s.begin();
            if (first[idx] < j) found = true;
        }
    }
    puts(found ? "YES" : "NO");
    return 0;
}
