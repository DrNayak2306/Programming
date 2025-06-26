/*
find the kth smallest product of two sorted arrays
*/
#include <bits/stdc++.h>
using namespace std;

class BSOnAnswer{
    /*
    for every element check the count of products less than or equal to the element
    time complexity: O(n1 * (log n2) * log (MAX-MIN))
    */
private:
    int getCount(vector<int> &nums2, long long x, long long target) {
        int low = 0, high = nums2.size()-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long prod = x * nums2[mid];
            if (prod > target && x >= 0 || prod <= target && x < 0) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (x >= 0) {
            return low;
        }
        return nums2.size() - low;
    }
public:
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, int k){
        long long low = -1e10, high = 1e10;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long count = 0;
            for (int x : nums1) {
                count += getCount(nums2, x, mid);
            }
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    string line;
    while (getline(cin, line)) {
        vector<int> nums1, nums2;
        int k;
        int x;
        stringstream ln1(line);
        while (ln1 >> x) {
            nums1.push_back(x);
        } 
        getline(cin, line);
        stringstream ln2(line);
        while (ln2 >> x) {
            nums2.push_back(x);
        }
        getline(cin, line);
        k = stoi(line);
        BSOnAnswer sol;
        cout << sol.kthSmallestProduct(nums1, nums2, k) << "\n";
    }
    return 0;
}