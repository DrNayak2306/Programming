#include <bits/stdc++.h>

using namespace std;

// 2115A
// solved using DP
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    int g = a[0];
    for (int i = 1; i < n; i++) {
        g = __gcd(g, a[i]);
    }
    int gCount = 0;
    for (int i : a) {
        gCount += (i == g);
    }
    if (g > 0) {
        cout << a.size() - g << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}