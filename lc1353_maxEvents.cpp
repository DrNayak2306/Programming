/*
Events is an array of [start_i, end_i] showing start and end dates of event i
An even can be attended for a single day also.
Return the maximum number of events that can be attended.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>> &events) {
        // simulate the process of attending an event day by day
        /*
        maintain a min heap of events sorted by end date and greedily attend early ending ones
        */
        int ans = 0;
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>> toAttend;
        for (int i = 0, day = 1; i < events.size() || !toAttend.empty(); ) {
            if (toAttend.empty()) {
                // all events until this day have been exhausted
                // fast forward to the first upcoming event
                day = events[i][0];
            }
            while (i < events.size() && events[i][0] == day) {
                // note down all events opening today
                toAttend.push(events[i][1]);
                i++;
            }
            if (day <= toAttend.top()) {
                ans++;
                day++;
            }
            // top of the queue shows the best possible choice
            // we accepted it, or rejected it
            // either case, decision is made, so remove from queue
            toAttend.pop();
        }
        return ans;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<vector<int>> events;
        for (int s, e; ss >> s >> e; events.push_back({s, e}));
        Solution obj;
        cout << obj.maxEvents(events) << endl;
    }
    return 0;
}