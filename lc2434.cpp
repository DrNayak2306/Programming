/*

*/

#include <bits/stdc++.h>

using namespace std;


template <class returnType>
pair<returnType, double> secondary(){
    time_t start_time = clock();
    returnType mainRet;
    time_t end_time = clock();
    return pair<mainRet, (double)(end_time-start_time)/CLOCKS_PER_SEC>;
}

int main(){
    string s;
    cin >>s;
    
    // brute-force solution
    // TLE for testcase in lc2434TLE.txt
    string c;
    int start = 0;
    time_t start_time = clock();
    while (!s.empty()){
        int j = start;
        for (int i = 0; i < s.size(); i++){
            if (s[i] < s[j]){
                j = i;
            }
        }
        start = (j == 0) ? 0 : j-1;
        c += s[j];
        s.erase(s.begin()+j);
    }
    time_t end_time = clock();
    cout <<"Time taken: " <<(double)(end_time-start_time)/CLOCKS_PER_SEC <<endl;
    return 0;
}