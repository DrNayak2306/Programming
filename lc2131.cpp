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

int main(){
    int n;
    cin >>n;
    vector<string> words(n);
    for (int i=0; i<n; i++)
        cin >>words[i];

    unordered_map<string, int> wordFreq;

    for (string word: words){
        wordFreq[word]++;
    }
    int palindromeLength = 0;
    bool oddTaken = false;
    for (string word: words){
        string rev = {word[1], word[0]};
        if (word != rev){
            palindromeLength += min(wordFreq[word], wordFreq[rev])*4;
        }
        else{
            palindromeLength += (wordFreq[word])*2 ;
            if (wordFreq[word]%2==1){
                if (!oddTaken) oddTaken = true;
                else palindromeLength -= 2;
            }
        }
        wordFreq[word] = 0;
        if (wordFreq.find(rev) != wordFreq.end())
            wordFreq[rev] = 0;
    }
    cout <<palindromeLength <<endl;
}