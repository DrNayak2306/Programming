/*
Beautiful edge case for O(n) solution
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k){
        // we keep a detection length of k, and iterate until key lies within k
        // once detected, we move k indices until next key is not detected or we reach end
        // this guarantees correct extraction for all keys lying at indices >= k

        // phase 1: extract for all keys @ < k
        // phase 2: extract for all keys @ >= k

        int n = nums.size();
        vector<int> ans;
        int i = 0, j = 0, limit;

        // phase 1
        while (i < k){
            if (nums[i] == key) j = i;
            i++;
        }

        i = 0;
        if (nums[j] == key){
            // j points to the last key within k-1
            limit = min(n-1, j+k);
            while (i <= limit && (i+k > n-1 || nums[i+k] != key)){
                ans.push_back(i);
                i++;
            }
        }
        // either we haven't found any keys within k-1
        // or we have extracted all numbers till end of array
        // or we have stopped with the next key just detected

        // phase 2
        while (i < n){
            if ((j=i+k) < n && nums[j] == key){
                ans.push_back(i);
                i++;
                limit = min(n-1, j+k);
                while (i <= limit && (i+k > n-1 || nums[i+k] != key)){
                    ans.push_back(i);
                    i++;
                }
            }
            else i++;
        }
        return ans;
    }
};
int main(){
    freopen("input.txt", "r", stdin);
    int t;
    string line;
    getline(cin, line);
    t = stoi(line);
    int x;
    while (t--){
        while (getline(cin, line)){
            stringstream lineStream(line);
            vector<int> nums;
            while (lineStream >> x) nums.push_back(x);
            int key, k;
            getline(cin, line); key = stoi(line);
            getline(cin, line); k = stoi(line);
            Solution obj;
            vector<int> ans = obj.findKDistantIndices(nums, key, k);
            for (int i: ans) cout <<i <<" "; cout <<"\n";
        }
    }
    return 0;
}