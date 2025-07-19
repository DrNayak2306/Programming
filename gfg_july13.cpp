/*
find the sum of all elements of an array not part of the longest increasing subsequence
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dynamicProg(vector<int> &arr) {
        // O(n^2) time and O(n) space
        int n = arr.size();
        vector<pair<int, int>> dp(n);
        int tot = accumulate(arr.begin(), arr.end(), 0);
        int maxLen = 0, minSum = INT_MAX;
        for (int i = 0; i < n; i++) {
            int len = 0;
            int sum = INT_MAX;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] < arr[i] && (len == 0 ||
                (dp[j].first > len || (dp[j].first == len && dp[j].second < sum))))
                {
                    len = dp[j].first;
                    sum = dp[j].second;
                }
            }
            if (len == 0) sum = 0;
            sum += arr[i];
            dp[i] = {len + 1, sum};
            if (maxLen == 0 || len > maxLen || sum < minSum) {
                maxLen = len;
                minSum = sum;
            }
        }
        return tot - minSum;
    }

};

int main(){
    freopen("input.txt", "r", stdin);
    string line;
    while (getline(cin, line)) {
        stringstream ln(line);
        vector<int> arr;
        for (int x; ln >> x; arr.push_back(x));
        Solution obj;
        cout << obj.dynamicProg(arr) << endl;
    }
    return 0;
}