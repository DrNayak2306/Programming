/*
Counting elements of array b that are smaller than or equal to each of the elements of array a
a and b are unsorted
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void displayAnswer(vector<int> &ans) {
        for (int i : ans) {
            cout << i << " ";
        } cout << "\n";
    }
    static vector<int> bruteForce(vector<int> a, vector<int> b) {
        /*
        by considering every element in cartesian product of a x b
        O(AB) time
        O(1) space
        */

        vector<int> ans;
        for (int i : a) {
            int cnt = 0;
            for (int j : b) {
                if (j <= i) {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
    static vector<int> better1(vector<int> a, vector<int> b) {
        /*
        using handwritten upper bound routine
        O((A+B)logB) time
        O(B) space
        */

        vector<int> ans;
        ranges::sort(b);
        for (int i : a) {
            int low = 0, high = b.size()-1;
            while (low <= high) {
                int mid = (low + high)/2;
                if (b[mid] > i) {
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }
            ans.push_back(low);
        }
        return ans;
    }
    static vector<int> better2 (vector<int> a, vector<int> b) {
        /*
        using STL upper bound routine
        O((A+B)logB) time
        O(B) space 
        */

        vector<int> ans;
        ranges::sort(b);
        for (int i: a) {
            ans.push_back(ranges::upper_bound(b, i)-b.begin());
        }
        return ans;
    }
    static vector<int> better3 (vector<int> a, vector<int> b) {
        /*
        using sorting and two pointers 
        O(AlogA + BlogB) time
        O(A) space
        */

        vector<int> ans(a.size());
        vector<pair<int, int>> sortedA;

        for (int i = 0; i < a.size(); i++) {
            sortedA.push_back({i, a[i]});
        }

        ranges::sort(sortedA, [](auto a, auto b){return a.second < b.second;});
        ranges::sort(b);
        for (int i = 0, j = 0; i < sortedA.size(); i++) {
            while (j < b.size() && b[j] <= sortedA[i].second) {
                j++;
            }
            ans[sortedA[i].first] = j;
        }
        return ans;
    }
    static vector<int> optimal (vector<int> a, vector<int> b) {
        /*
        maintaining a count array using prefix sum
        O(A+B) time
        O(A+B+max(b)) space
        */

        int m = *ranges::max_element(b);
        vector<int> ans, leCount(m+1, 0); // array contains no negatives
        for (int i : b) {
            leCount[i]++;
        }
        for (int i = 1; i <= m; i++) {
            leCount[i] += leCount[i-1];
        }
        for (int i : a) {
            ans.push_back(leCount[i]);
        }
        return ans;
    }
    vector<vector<int> (*)(vector<int>, vector<int>)> algs = {&bruteForce, &better1, &better2, &better3, &optimal};
public:
    Solution() {
        freopen("input.txt", "r", stdin);
        string line;
        for (string l1, l2; getline(cin, l1), getline(cin, l2);) {
            stringstream ls1(l1), ls2(l2);
            vector<int> a, b;
            for (int x; ls1 >> x; a.push_back(x));
            for (int x; ls2 >> x; b.push_back(x));
            vector<int> ans = algs[4](a, b);
            displayAnswer(ans);
        }
    }
};

int main(){
    Solution sol;
    return 0;
}