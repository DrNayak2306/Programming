/*
return the top k sums with one element from a and another from b
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKSumPairs(vector<int> &a, vector<int> &b, int k) {
        priority_queue<pair<int, pair<int, int>>> candidates;
        set<pair<int, int>> vis;

        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        candidates.push({a[0] + b[0], {0, 0}});
        vis.insert({0, 0});

        vector<int> ans;
        while (ans.size() < k) {
            auto top = candidates.top();
            candidates.pop();
            int sum = top.first;
            int i = top.second.first, j = top.second.second;

            ans.push_back(sum);

            if (i + 1 < a.size() && vis.find({i + 1, j}) == vis.end()) {
                candidates.push({a[i+1] + b[j], {i+1, j}});
                vis.insert({i + 1, j});
            }
            if (j + 1 < b.size() && vis.find({i, j+1}) == vis.end()) {
                candidates.push({a[i]+b[j+1], {i, j+1}});
                vis.insert({i, j+1});
            }
        }
        return ans;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    string line;
    while (getline(cin, line)) {
        stringstream ln1(line);
        vector<int> a;
        for (int x; ln1 >> x; a.push_back(x));
        getline(cin, line);
        stringstream ln2(line);
        vector<int> b;
        for (int x; ln2 >> x; b.push_back(x));
        getline(cin, line);
        int k = stoi(line);

        Solution obj;
        for (int i : obj.topKSumPairs(a, b, k)) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}