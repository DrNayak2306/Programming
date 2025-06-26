#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int k;
    cin >>s >>k;
    int n = s.size();
    vector<vector<int>> charFreq(5, vector<int>(n, 0));
    charFreq[s[0]-'0'][0] = 1;
    for (int i=1; i<n; i++){
        for (int j=0; j<5; j++)
            charFreq[j][i] = charFreq[j][i-1];
        charFreq[s[i]-'0'][i]++;
    }
    return 0;
}