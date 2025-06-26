/*
TLE for TLElc10.txt
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool match(string s, int si, string p, int pi){
        if (pi == p.size()){
            if (si == s.size()) return true;
            return false;
        }
        
        if (pi+1 < p.size() && p[pi+1] == '*'){
            // try 0 match from s
            if (p[pi] == '.')
                while (si <= s.size()){
                    if (match(s, si, p, pi+2))
                        return true;
                    si++;
                }
            else {
                if (match(s, si, p, pi+2)) return true;
                while (si < s.size() && s[si] == p[pi]){
                    if (match(s, si+1, p, pi+2))
                        return true;
                    si++;
                }
            }

        }
        else if (si < s.size())
            return (s[si]==p[pi] || p[pi]=='.') && match(s, si+1, p, pi+1);

        return false;
    }
public:
    bool isMatch(string s, string p) {
        return match(s, 0, p, 0);
    }
};

int main(){
    string s, p;
    cin >>s >>p;
    Solution sol;
    cout << ( (sol.isMatch(s, p))? "yes" : "no" ) <<endl;
}