/*
max difference between even and odd frequency

only one approach: using frequency map
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

int main(){
    string s;
    cin >>s;

    unordered_map<char, int> freq;
    int oddMax = 0, evenMin = s.size();
    for (char c: s){
        freq[c]++;
    }
    for (auto i: freq){
        if (i.second%2 == 0)
            evenMin = min(evenMin, i.second);
        else
            oddMax = max(oddMax, i.second);
    }
    int res = oddMax-evenMin;
    cout <<res <<endl;
    return 0;
}