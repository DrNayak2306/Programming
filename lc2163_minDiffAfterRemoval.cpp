/*
Given an array nums of length 3n, return the minimum possible difference by removal of any n numbers, obtained by subtracting the sum of the remaining last n elements from the sum of the remaining first n elements.
*/
#include <bits/stdc++.h>

using namespace std;

class BruteForce {
    // factorial time complexity
    // takes forever
    vector<int> nums;
    int n;
    long long ans;
    vector<bool> removed;
private:
    void recur(int i, int cnt, int f, long long firstSum, int s, long long secondSum) {
        if (cnt == n / 3) {
            ans = min(ans, firstSum - secondSum);
            return;
        }
        if (i == n) {
            return;
        }

        removed[i] = true;
        recur(i + 1, cnt + 1, f, firstSum, s, secondSum);

        removed[i] = false;
        if (f < 2*n/3) {
            firstSum += nums[i] - nums[f++];
        } else if (s < n){
            secondSum += nums[i] - nums[s++];
        }
        recur(i + 1, cnt, f, firstSum, s, secondSum);

    }
public:
    long long minimumDifference(vector<int> &arr) {
        nums = arr;
        n = nums.size();
        ans = LLONG_MAX;
        int f = n / 3, s = 2 * f;
        long long firstSum = accumulate(nums.begin() + f, nums.begin() + s, 0LL);
        long long secondSum = accumulate(nums.begin() + s, nums.end(), 0LL);
        removed = vector<bool>(n, false);
        recur(0, 0, f, firstSum, s, secondSum);
        return ans;
    }
};

class Optimal {
    // to get min diff, we need min first sum and max second sum
    // so maintain an array with the min sum of n elements till that index
    // and an array with the max sum of n elements from that index onwards
    // achieve this optimally by using priority queues
public:
    long long minimumDifference(vector<int> &nums) {
        int n = nums.size();
        vector<long long> firstSum(n), secondSum(n);
        priority_queue<int> maxQ;
        priority_queue<int, vector<int>, greater<int>> minQ;
        
        firstSum[0] = nums[0];
        maxQ.push(nums[0]);
        for (int i = 1; i < n; i++) {
            firstSum[i] = firstSum[i - 1];
            if (i < n/3) {
                firstSum[i] += nums[i];
                maxQ.push(nums[i]);
            } else if (nums[i] < maxQ.top()) {
                firstSum[i] += nums[i] - maxQ.top();
                maxQ.pop();
                maxQ.push(nums[i]);
            }
        }
        
        secondSum[n - 1] = nums[n - 1];
        minQ.push(nums[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            secondSum[i] = secondSum[i + 1];
            if (i >= 2*n/3) {
                secondSum[i] += nums[i];
                minQ.push(nums[i]);
            } else if (nums[i] > minQ.top()) {
                secondSum[i] += nums[i] - minQ.top();
                minQ.pop();
                minQ.push(nums[i]);
            } 
        }
        long long ans = LLONG_MAX;
        for (int i = n/3 - 1; i < 2*n/3; i++) {
            ans = min(ans, firstSum[i] - secondSum[i + 1]);
        }
        return ans;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    string line;
    while (getline(cin, line)) {
        stringstream ln(line);
        vector<int> nums;
        for (int x; ln >> x; nums.push_back(x));

        Optimal sol;
        cout << sol.minimumDifference(nums) << endl;
    }
    return 0;
}