/*

*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    string word;
    int k;
    cin >>word >>k;

    unordered_map<char, int> charMap;
    for (char c: word)
        charMap[c]++;
    
    vector<int> freq;
    for (auto& i: charMap)
        freq.push_back(i.second);
    sort(begin(freq), end(freq));

    int suffix = accumulate(begin(freq), end(freq), 0);
    int ans = INT_MAX;

    for (int i = 0, j, last, prefixDiff = 0, suffixDiff, winSum; i < freq.size();){
        cout <<freq[i] <<endl;
        j = i;
        winSum = 0;
        while (j < freq.size() && freq[j]-freq[i] <= k){
            winSum += freq[j];
            j++;
        }
        last = freq[j-1];
        suffixDiff = suffix-winSum - (freq.size() - j) * last;
        ans = min(ans, suffixDiff + prefixDiff);
        cout <<"ans:"<<ans <<endl;

        prefixDiff += winSum;
        suffix -= winSum;
        i = j;
    }
    cout <<ans <<endl;
    return 0;
}