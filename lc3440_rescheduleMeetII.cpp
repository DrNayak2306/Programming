/*
you can reschedule 1 meeting by changing the relative ordering
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    two pass solution:
    when we are iterating through the meetings, we can immediately see that we can combine the 
    left and right gaps by shifting if immediately after the previous or before the next

    additionally, if there is a free slot to fit this meet, we get a local best of leftGap + rightGap + meetDur
    */
    int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime) {
        int n = startTime.size();

        int ans = 0;

        // left pass
        for (int i = 0, maxGap = 0, gap, dur; i < n; i++) {
            gap = 0;
            dur = endTime[i] - startTime[i];

            gap += startTime[i] - (i > 0 ? endTime[i - 1] : 0);
            gap += ((i < n - 1) ? startTime[i + 1] : eventTime) - endTime[i];
            if (dur <= maxGap) gap += dur;
            ans = max(ans, gap);
            maxGap = max(maxGap, startTime[i] - ((i > 0) ? endTime[i - 1] : 0));
        }
        // right pass
        for (int i = n - 1, maxGap = 0, gap, dur; i >= 0; i--) {
            gap = 0;
            dur = endTime[i] - startTime[i];
            
            gap += startTime[i] - (i > 0 ? endTime[i - 1] : 0);
            gap += ((i < n - 1) ? startTime[i + 1] : eventTime) - endTime[i];
            if (dur <= maxGap) gap += dur;
            ans = max(ans, gap);
            maxGap = max(maxGap, ((i < n - 1) ? startTime[i + 1] : eventTime) - endTime[i]);
        }

        return ans;
    }    
};

int main(){
    freopen("input.txt", "r", stdin);
    string line;
    while (getline(cin , line)) {
        int eventTime = stoi(line);
        vector<int> startTime, endTime;
        getline(cin, line);
        stringstream ln1(line);
        getline(cin, line);
        stringstream ln2(line);
        for (int x; ln1 >> x; startTime.push_back(x));
        for (int x; ln2 >> x; endTime.push_back(x));
        Solution obj;
        cout << obj.maxFreeTime(eventTime, startTime, endTime) << endl;
    }
    return 0;
}