/*
find the kth smallest product of two sorted arrays
*/
#include <bits/stdc++.h>
using namespace std;

class BSCounting{
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

class DivideAndConquer {
/*
this approach is similar to finding the position of an element in a matrix sorted row wise and column wise

divide nums1 into nums1[0, pos1) for negative values and nums1[pos1, n1) for non-negative values
divide nums2 into nums2[0, pos2) for negative values and nums2[pos2, n2) for non-negative values

        0            pos1-1  pos1          n1-1
       .-------------------.-------------------.
     0 | inc right to left | inc right to left |
       | inc bottom to top | inc top to bottom |
       |                   |                   |
       |                   |                   |
       |                   |                   |
       |                   |                   |
pos2-1 |                   |                   |
       |-------------------+-------------------| 
  pos2 | inc left to right | inc left to right |
       | inc bottom to top | inc top to bottom |
       |                   |                   |
       |                   |                   |
       |                   |                   |
       |                   |                   |
  n2-1 |                   |                   |
       '-------------------'-------------------'
*/
public:
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k){
        int n1 = nums1.size(), n2 = nums2.size();
        int pos1 = 0, pos2 = 0;
        while (pos1 < n1 && nums1[pos1] < 0) {
            pos1++;
        }
        while (pos2 < n2 && nums2[pos2] < 0) {
            pos2++;
        }
        auto countLessEq = [&](long long v) -> long long {
            int i, j;
            long long prod, cnt = 0;

            // top left matrix
            // inc from right to left
            // inc from bottom to top
            i = 0, j = pos2 - 1;
            while (i < pos1 && j >= 0) {
                prod = 1LL * nums1[i] * nums2[j];
                if (prod <= v) {
                    cnt += pos1 - i;
                    j--;
                } else {
                    i++;
                }
            }
            // top right matrix
            // inc from right to left
            // inc from top to bottom
            i = pos1, j = 0;
            while (i < n1 && j < pos2) {
                prod = 1LL * nums1[i] * nums2[j];
                if (prod <= v) {
                    cnt += n1 - i;
                    j++;
                } else {
                    i++;
                }
            }
            // bottom left matrix
            // inc from left to right
            // inc from bottom to top
            i = 0, j = pos2;
            while (i < pos1 && j < n2) {
                prod = 1LL * nums1[i] * nums2[j];
                if (prod <= v) {
                    cnt += n2 - j;
                    i++;
                } else {
                    j++;
                }
            }
            // bottom right matrix
            // inc from left to right
            // inc from top to bottom
            i = pos1, j = n2 - 1;
            while (i < n1 && j >= pos2) {
                prod = 1LL * nums1[i] * nums2[j];
                if (prod <= v) {
                    cnt += j + 1 - pos2;
                    i++;
                } else {
                    j--;
                }
            }

            return cnt;
        };

        long long low = -1e10, high = 1e10;
        while (low <= high) {
            long long mid = (low + high)/2;
            long long count = countLessEq(mid);
            if (count >= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
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
        int k, x;
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
        BSCounting sol1;
        sol1.kthSmallestProduct(nums1, nums2, k);
        // DivideAndConquer sol2;
        // sol2.kthSmallestProduct(nums1, nums2, k);
    }
    return 0;
}