/*
minimize the maximum difference of p pairs from nums
constraint:
* no index can be a member of multiple pairs
*/

#include <bits/stdc++.h>

using namespace std;

bool isValid(vector<int> &sortedNums, int p, int maxDiff){
    int i = 0;
    while (i < sortedNums.size()-1){
        if (sortedNums[i] + maxDiff >= sortedNums[i+1]){
            p--;
            if (p == 0)
                return true;
            i++;
        }
        i++;
    }
    return false;
}

int main(){
    int n;
    cin >>n;
    vector<int> nums(n);
    for (int i=0; i<n; i++) cin >>nums[i];
    int p;
    cin >>p;

    // brute-force
    // vector<int> sortedNums(nums); sort(sortedNums.begin(), sortedNums.end());
    // vector<bool> taken(n, false);
    // int maxDiff = INT_MIN;
    // for (int i = 0; i < n && p > 0; i++){
    //     if (taken[i]) continue;

    //     pair<int, int> choice;
    //     int minDiff = INT_MAX;
    //     for (int j = i+1; j < n; j++){
    //         if (taken[j]) continue;

    //         int diff = abs(sortedNums[i]-sortedNums[j]);
    //         if (diff < minDiff){
    //             choice = {i, j};
    //             minDiff = diff;
    //         }
    //     }
    //     taken[choice.first] = taken[choice.second] = true;
    //     maxDiff = max(maxDiff, minDiff);
    //     p--;
    // }
    // cout <<maxDiff <<endl;

    // optimal
    vector<int> sortedNums(nums); sort(sortedNums.begin(), sortedNums.end());
    int low = 0, high = sortedNums.back()-sortedNums.front(), mid;
    while (low <= high){
        mid = (low + high)/2;
        if (isValid(sortedNums, p, mid)){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout <<low <<endl;
    return 0;
}