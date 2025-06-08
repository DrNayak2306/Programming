/*
lexicographically sorted sequence of numbers 1 to n
to be done in O(n) time and O(1) space
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >>n;
    vector<int> res;
    int num=1;
    do{
        if (num <= n){
            res.push_back(num);
            // before increasing current digit, check if lexically smaller numbers are possible
            num *= 10;
        } else{
            num = num/10 + 1;
            // drop to the lexically smallest number
            while (num % 10 == 0){
                num /= 10;
            }
        }
    } while (num != 1);
    for (int i: res){
        cout <<i <<" ";
    }
    cout <<endl;
    return 0;
}