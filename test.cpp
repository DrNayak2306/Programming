#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int both = 0, on = 0, off = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        both ^= arr[i];
    }
    int diff = 1;
    while ((both & diff) == 0) {
        diff <<= 1;
    }
    for (int i : arr) {
        if ((i & diff)) {
            on ^= i;
        } else {
            off ^= i;
        }
    }
    cout << min(on, off) << " " << max(on, off) << endl;
    return 0;
}