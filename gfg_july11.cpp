/*
number of binary strings of length n with at least one consecutive pair of 1s
*/
#include <bits/stdc++.h>

using namespace std;

class DP {
private:
    int count(int n, int i, int prev, vector<vector<int>> &dp) {
        if (i > n) return 0;
        if (dp[i][prev] != -1) return dp[i][prev];
        int res;
        if (prev == 0) {
            res = count(n, i + 1, 0, dp) + count(n, i + 1, 1, dp);
        }
        // count(x10), count(x11)
        else {
            res = count(n, i + 1, 0, dp) + (1 << (n - i));
        }
        return dp[i][prev] = res;
    }
public:
    int topDown(int n) {
        // O(n) time and O(n) space
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return count(n, 1, 0, dp);
    }
    // reducing stack space and realizing that all values before previous are irrelevant
    int bottomUp(int n) {
        // O(n) time and O(1) space
        vector<int> dpPrev(2, 0);
        for (int i = 1; i < n; i++) {
            vector<int> dpCur(2);
            dpCur[0] = dpPrev[0] + dpPrev[1];
            dpCur[1] = dpPrev[0] + (1 << i-1);
            dpPrev = dpCur;
        }
        return dpPrev[0] + dpPrev[1];
    }
    // reducing the shift operations
    int complementCounting(int n) {
        // O(n) time and O(1) space
        // subtract number of strings with no consecutive ones from total number of binary strings of length 1
        // prev0 is the number of strings till prev index ending with 0 and having no consecutive ones
        // prev1 is the number of string till prev index ending with 1 and having no consective ones
        int prev0 = 1, prev1 = 1;
        for (int i = 1; i < n; i++) {
            int cur0 = prev0 + prev1;
            int cur1 = prev0;
            prev0 = cur0;
            prev1 = cur1;
        }
        return (1 << n) - (prev0 + prev1);
    }
    int nthFib(int n) {
        // O(log n) time and O(log n) space
        // observe from previous function that
        // zn = zn-1 + on-1 ... (1)
        // on = zn-1 ... (2)
        // => zn = zn-1 + zn-2 = fib(n) ... (3) [from (1) and (2)]
        // result = zn + on = zn + zn-1 = zn+1 = fib(n+1) ... (4) [from (3)]

        // matrix exponentiation to efficiently compute fib(n+1)
        
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    string line;
    while (getline(cin, line)) {
        int n = stoi(line);
        DP sol;
        cout << sol.bottomUp(n) << " " << sol.complementCounting(n) << endl;
    }
    return 0;
}