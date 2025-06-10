/*
given an array of children with ratings, candies to be alloted with rules:
1. each must get >= 1
2. if child has higher rating than neighbor, he must get more

aim is to minimize total candies distributed
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int constantSpace(vector<int>& ratings) {
        long total = 1;
        int prevAllotment = 1,
            allotment, 
            limit = INT_MAX,
            start = 0;
        bool climbing = false;
        for (int i=1; i<ratings.size(); i++){
            if (ratings[i] > ratings[i-1]){
                if (!climbing){
                    total += fixAllotments(start, i, prevAllotment, limit);
                    limit = INT_MAX;
                    prevAllotment = 1;
                    climbing = true;
                }
                allotment = prevAllotment + 1;
            }
            else{
                if (climbing){
                    if (ratings[i]==ratings[i-1])
                        limit = INT_MAX;
                    else 
                        limit = prevAllotment;
                    allotment = 1;
                    start = i;
                    climbing = false;
                }
                else if (ratings[i]==ratings[i-1]){
                    total += fixAllotments(start, i, prevAllotment, limit);
                    limit = INT_MAX;
                    allotment = 1;
                    start = i;
                }
                else{
                    allotment = prevAllotment - 1;
                }
            }
            total += allotment;
            prevAllotment = allotment;
        }
        if (!climbing)
            total += fixAllotments(start, ratings.size(), prevAllotment, limit);
        return total;
    }
    int straightForward(vector<int> &ratings){
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i=1; i<n; i++){
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i-1]+1;
        }
        int total = candies[n-2];
        for (int i=n-2; i>=0; i--){
            if (ratings[i] > ratings[i+1])
                candies[i] = max(candies[i], candies[i+1]+1);
            total += candies[i];
        }
        return total;
    }
private:
    long fixAllotments(int start, int end, int prevAllotment, int limit){
        long res = 0;
        res = (end-start)*(1-prevAllotment); // make sure minimum is 1 in the range till start
        int diff = (2-prevAllotment-limit);
        if (diff >= 0)
            res += diff+1; // allot diff+1 extra candies to the left neighbour of start
        return res;
    }

};
int main(){
    int n;
    cin >>n;
    vector<int> ratings(n);
    for (int i=0; i<n; i++)
        cin >>ratings[i];

    Solution sol;
    cout <<sol.constantSpace(ratings) <<endl;
    cout <<sol.straightForward(ratings) <<endl;
    return 0;
}