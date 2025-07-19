/*
a subsequence is valid if 
(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k = ... = (sub[x - 2] + sub[x - 1]) % k
return the length of the longest valid subsequence of nums
*/
#include <bits/stdc++.h>

using namespace std;

class TDP {
    // tabulated DP
public:
    int maximumLength(vector<int> &nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        // there are k different previous element remainders
        // for each, there are k different subsequences possible for k types of sums

        // thought process:
        // as and when we see an element, we add its contribution to every kind of previously seen remainder (each previous seen remainder can be a part of k subsequences)
        int ans = 0;
        for (int i : nums) {
            int rem = i % k;
            for (int r = 0; r < k; r++) {
                dp[rem][r] = dp[(r - rem + k) % k][r] + 1;
                ans = max(ans, dp[rem][r]);
            }
        }
        return ans;
    }
};

class Insight {
    // insightful simplification
public:
    int maximumLength(vector<int> &nums, int k) {
        // in the above solution we were considering all possibilities
        // when we are considering an element, check 

    }
};

int main(){
    freopen("input.txt", "r", stdin);
    string line;
    while (getline(cin, line)) {
        stringstream ln(line);
        vector<int> nums;
        for (int x; ln >> x; nums.push_back(x));
        getline(cin, line);
        int k = stoi(line);
        TDP sol1;
        cout << sol1.maximumLength(nums, k) << endl;
    }
    return 0;
}