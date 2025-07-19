/*
there are n rooms, and meetings[] that are to be held in these n rooms
a room occupied by a meeting is freed only after the meeting ends
if a meeting has multiple rooms available, the one with the smallest number is booked

return the most booked room
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostBooked (int n, vector<vector<int>> &meetings) {
        vector<int> bookings(n, 0);
        sort(meetings.begin(), meetings.end());
        typedef pair<long long, int> pairLLI;
        priority_queue<pairLLI, vector<pairLLI>, greater<pairLLI>> busy;
        priority_queue<int, vector<int>, greater<>> free;

        for (int i = 0; i < n; i++) {
            free.push(i);
        }

        for (auto &slot : meetings) {
            pairLLI top;
            while (!busy.empty() && (top = busy.top()).first <= slot[0]) {
                busy.pop();
                free.push(top.second);
            }
            if (free.empty()) {
                top = busy.top();
                busy.pop();
                top.first += slot[1] - slot[0];
            } else {
                top = {slot[1], free.top()};
                free.pop();
            }
            bookings[top.second]++;
            busy.push(top);
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (ans == -1 || bookings[i] > bookings[ans]) {
                ans = i;
            }
        }
        return ans;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    string line;
    while (getline(cin, line)) {
        int n = stoi(line);
        getline(cin, line);
        stringstream ln(line);
        vector<vector<int>> meetings;
        for (int x, y; ln >> x >> y; meetings.push_back({x, y}));
        Solution obj;
        cout << obj.mostBooked(n, meetings) << endl;
    }
    return 0;
}