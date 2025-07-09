/*
sum of the minimum of every subarray
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int monotonicStack(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> leftNle, rightNl;
        for (int i = 0; i < n; i++) {
            while (!leftNle.empty() && arr[i] < arr[leftNle.top()]) {
                leftNle.pop();
            }
            if (!leftNle.empty()) {
                left[i] = leftNle.top();
            }
            int j = n-1-i;
            while (!rightNl.empty() && arr[j] <= arr[rightNl.top()]) {
                rightNl.pop();
            }
            if (!rightNl.empty()) {
                right[j] = rightNl.top();
            }
            leftNle.push(i);
            rightNl.push(j);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (i - left[i]) * (right[i] - i) * arr[i];
        }
        return ans;
    }
    int dynamicProgramming(vector<int> &arr) {
        int n = arr.size();
        stack<int> monotonic;
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!monotonic.empty() && arr[i] < arr[monotonic.top()]) {
                monotonic.pop();
            }
            if (monotonic.empty()) {
                dp[i] = (n - i) * arr[i];
            }
            else {
                dp[i] = (monotonic.top() - i) * arr[i] + dp[monotonic.top()];
            }
            monotonic.push(i);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<int> arr;
        for (int x; ss >> x; arr.push_back(x));
        Solution obj;
        cout << obj.dynamicProgramming(arr) << endl;
    }
    return 0;
}