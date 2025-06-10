#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >>s;
    
    string c, t;
    
    int i = 0;
    int start = 0;
    while (start < s.size()){
        // brute-force min extraction
        i = min_element(s.begin()+start, s.end())-s.begin(); 
        while (!t.empty() && s[i] >= t.back()){
            c += t.back();
            t.pop_back();
        }
        t.append(s.begin()+start, s.begin()+i);
        c += s[i];
        start = i + 1;
    }
    while (!t.empty()){
        c += t.back();
        t.pop_back();
    }
    cout <<c <<endl;
    return 0;
}