/*
initially s = "a"
there is an array of two operations:
0 - to append s to itself
1 - to append each character of s incremented by 1 (mod 26) to itself

return kth char
*/

#include <bits/stdc++.h>

using namespace std;

class Iteration {
public:
    char kthCharacter (long long k, vector<int>& operations) {
        char ans = 0;
        while (k > 1) {
            int i = __lg(k);
            if ((1LL << i) == k) {
                --i;
            }
            ans += operations[i];
            k = (k - (1LL << i));
        }
        return ans % 26 + 'a';
    }
};

class Math {
public:
    char kthCharacter (long long k, vector<int> &operations) {
        int i = 0;
        k--; // important to adjust smallest power of 2
        int ans = 0;
        for (int i = 0; (1LL << i) < k; i++){
            if (k & (1LL << i)) {
                ans += operations[i];
            }
        }
        return ans % 26 + 'a';
    }
};

int main(){
    // observation:
    // s[2^t + x] = op[t] on s[x] = op[t] + s[x]
    // this logic is applied until x is greater than 1
    freopen("input.txt", "r", stdin);
    string line;
    while (getline(cin, line)){
        long long k = stoll(line);
        getline(cin, line);
        stringstream ln(line);
        vector<int> operations;
        for (int x; ln >> x; operations.push_back(x));
        Iteration sol1;
        Math sol2;
        cout << "sol1: " << sol1.kthCharacter(k, operations) << " sol2: " << sol2.kthCharacter(k, operations) << "\n";
    }
    return 0;
}