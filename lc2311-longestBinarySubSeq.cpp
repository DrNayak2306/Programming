/*
given a binary string s and k, return the longest subsequence in s that is less than or equal to k
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int bits = 32 - __builtin_clz(k);
        int cnt = 0;
        int num = 0;
        
        for (int i = 0; i < s.size(); i++) {
            char ch = s[s.size() - 1 - i];
            if (ch == '1') {
                if (i < bits && (num += 1 << i) <= k) {
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    string line;
    getline(cin, line);
    int t = stoi(line);
    while (t--) {
        string s;
        int k;
        getline(cin, line);
        s = line.substr(0, line.find('\n'));
        getline(cin, line);
        k = stoi(line);
        Solution obj;
        cout << obj.longestSubsequence(s, k) << "\n";
    }
    return 0;
}