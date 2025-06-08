/*
given an array of children with ratings, candies to be alloted with rules:
1. each must get >= 1
2. if child has higher rating than neighbor, he must get more
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >>n;
    vector<int> ratings(n);
    for (int i=0; i<n; i++)
        cin >>ratings[i];
    
    // brute-force
    /*
    first do minimum filling for all increasing sequences
            *
           *  *
          *    *
         *      *
            *
           *
          * 
         * 
    */
    return 0;
}