/*
2131. Longest palindrome by concatenating two letter words

INPUT
lc cl gg
OUTPUT
6 (lcggcl)

O(n^2) solution:
    nested for-loop for counting frequency
    set for avoiding overcounting
*/

#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string word){
    int l = 0, r = word.size()-1;
    while (l < r){
        if (word[l] != word[r])
            return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i=0; i<n; i++){
        cin >> words[i];
    }

    int res = 0, even = 0;
    bool odd = false;
    set<string> seen;
    
    // O(n)
    for (auto i : words){

        // O(log n)
        if (seen.find(i) != seen.end())
            continue;
        int cnt = 0;

        // O(n)
        for (auto j : words){
            if (i == j)
                cnt++;
        }
        if (isPalindrome(i)){
            if (cnt % 2 == 1){
                odd = true;
                res += (cnt-1)*2;
            }
            else
                res += cnt*2;
        }

        // O(n)
        else{
            string k = i;
            reverse(k.begin(), k.end());
            int revCnt = 0;
            for (auto j : words){
                if (j == k){
                    revCnt++;
                }
            }
            res += min(cnt, revCnt)*2;
        }
    }

    if (odd)
        res += 2;

    cout << res << endl;
    
    return 0;
}