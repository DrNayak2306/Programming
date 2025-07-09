/*
binary search + prefix sum
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
public:
    int bruteForce(vector<int> &arr, int k, int w) {
        int n = arr.size();
        int maxMinHeight = 0;

        while (true) {
            vector<int> water(n, 0);
            bool possible = true;
            int days = 0;

            for (int i = 0; i < n; i++) {
                if (i > 0) {
                    // optimization over iterating through next w elements for every element
                    water[i] = water[i - 1];
                }
                if (i >= w) {
                    water[i] -= water[i-w];
                }
                int height = arr[i] + water[i];
                if (height < maxMinHeight) {
                    int inc = maxMinHeight - height;
                    water[i] += inc;
                    
                    days += inc;
                    if (days > k) {
                        possible = false;
                        break;
                    }
                }

            }
            if (!possible) {
                break;
            }
            maxMinHeight++;
        }
        return maxMinHeight - 1;
    }
    int binarySearch(vector<int> &arr, int k, int w) {
        int n = arr.size();
        auto isPossible = [&](int maxMinHeight) -> bool {
            vector<int> water(n, 0);
            int days = 0;
            
            for (int i = 0; i < n; i++) {
                if (i > 0) {
                    water[i] = water[i-1];
                }
                if (i >= w) {
                    water[i] -= water[i - w];
                }
                int height = arr[i] + water[i];
                if (height < maxMinHeight) {
                    int inc = maxMinHeight - height;
                    days += inc;
                    if (days > k) {
                        return false;
                    }
                }
            }
            return true;
        };

        int low = *min_element(arr.begin(), arr.end()), high = low + k;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int k, w;
        cin >> k >> w;
        
        Solution obj;
        cout << obj.bruteForce(arr, k, w) << " ";
        cout << obj.binarySearch(arr, k, w) << endl;
    }
    return 0;
}