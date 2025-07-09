/*
Problem Statement:
Given a string s and an integer k, return the longest possible substring that repeats k times and is the lexicographically largest if multiple such subsequences exist.
*/

/*
Solutions:
1. Brute force - Generate all possible subsequences and score the answer
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// the one I could manage to find
class BackTrack {
private:
    void generate(string &ans, vector<int> &freq, string s, int k) {
        static string compare = "";

        bool isValid;
        if (compare.empty()){
            isValid = true;
        } else {
            int cnt = 0, i = 0, j = 0;
            while (i < s.size() && cnt < k) {
                if (s[i] == compare[j]) {
                    j++;
                    if (j == compare.size()) {
                        j = 0;
                        cnt++;
                    }
                }
                i++;
            }
            isValid = (cnt == k);
        }
        if (isValid) {
            if (compare.size() > ans.size() || compare > ans) {
                ans = compare;
            }
            for (char ch = 'z'; ch >= 'a'; ch--) {
                if (freq[ch - 'a'] >= k) {
                    compare.push_back(ch);
                    generate(ans, freq, s, k);
                    compare.pop_back();
                }
            }
        }
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        string ans = "";
        generate(ans, freq, s, k);
        return ans;
    }
};

class Enumerate {
private:
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        auto isValid = [&](string cmp) -> bool {
            int i = 0, j = 0, cnt = 0;
            if (cmp.empty()) {
                return true;
            }
            while (i < s.size() && cnt < k) {
                if (s[i] == cmp[j]) {
                    j++;
                    if (j == cmp.size()) {
                        j = 0;
                        cnt++;
                    }
                }
                i++;
            }
            return cnt == k;
        };
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        string ans = "";
        queue<string> frontier({""});
        while (!frontier.empty()) {
            string cur = frontier.front();
            frontier.pop();
            
            for (char c = 'a'; c <= 'z'; c++) {
                if (freq[c - 'a'] >= k) {
                    string next = cur;
                    next.push_back(c);
                    if (isValid(next)) {
                        frontier.push(next);
                    }
                }
            }
            ans = cur;
        }
        return ans;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    string line;
    int t;
    getline(cin, line);
    t = stoi(line);
    while (t--) {
        string s;
        int k;
        
        getline(cin, line);
        s = line.substr(0, line.find('\n'));

        getline(cin, line);
        k = stoi(line);
        
        Enumerate sol;
        cout << sol.longestSubsequenceRepeatedK(s, k) << "\n";
    }
}