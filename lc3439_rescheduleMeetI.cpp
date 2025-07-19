/*
get the maximum free time by rescheduling at most k meets by maintaining their relative ordering
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    sliding window:
    if we are given a window of t events (t <= k), then we can get max free time by left
    aligning or right aligning all the events within the window
    */
    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime) {
        int n = startTime.size();
        int ans = 0;
        for (int l = 0, r = 0, cnt = 0, freeTime = startTime[0]; r < n; r++) {
            freeTime += ((r < n - 1) ? startTime[r + 1] : eventTime) - endTime[r];
            if (cnt > k) {
                if (startTime[l] == 0) l++;
                freeTime -= startTime[l] - ((l > 0) ? endTime[l - 1] : 0);
                cnt--;
            }
            ans = max(ans, freeTime);
            if (startTime[r] != 0) cnt++;
        }
        return ans;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    string line;
    while (getline(cin, line)) {
        int eventTime = stoi(line.substr(0, line.find(' ')));
        int k = stoi(line.substr(line.find(' ')));
        getline(cin, line);
        stringstream ln1(line);
        getline(cin, line);
        stringstream ln2(line);
        vector<int> startTime, endTime;
        for (int x, y; ln1 >> x, ln2 >> y; startTime.push_back(x), endTime.push_back(y));
        Solution obj;
        cout << obj.maxFreeTime(eventTime, k, startTime, endTime) << endl;
    }
    return 0;
}