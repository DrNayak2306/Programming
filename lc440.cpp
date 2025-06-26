/*
find the kth smallest number in the lexicographical ordering of numbers 1..n
*/

#include <iostream>
#include <climits>

using namespace std;

int position(int n, int x){
    if (x > n)
        return INT_MAX;
    int cnt = 0;
    int msd = x;
    while (msd > 9){
        msd /= 10;
    }
    // cout <<"msd: " <<msd <<"\n";
    for (int i = 1; i <= 9 && i <= msd; i++){
        int check = i, base = 1;

        // O(log n)
        while (i < n/base){
            if (x/base == i) break;
            cnt += base;
            base *= 10;
            check = i * base;
        }
        // O(1)
        if (i == n / base) 
            cnt += n - check + 1;
        else if (i == msd)
            cnt += x - check +1;
    }
    
    return cnt;
}

int binarySearch(int n, int k){
    int ans;
    
    int msd_k = 9, msd_n = n;
    while (position(n, msd_k) > k){
        msd_k--;
    }
    while (msd_n > 9){
        msd_n /= 10;
    }
    int low = msd_k, high, mid;
    if (msd_k == msd_n){
        high = n;
    }
    else {
        high = msd_k;
        while (high < n){
            high = 10*high + 9;
        }
        high /= 10;
    }
    cout <<low <<", " <<high <<endl;
    int pos;
    while (low <= high){    
        mid = (low+high)/2;
        pos = position(n, mid);
        // cout <<low <<", "<< mid<<" @ " <<pos <<", " <<high <<endl;
        if (pos == k){
            ans = mid;
            break;
        } else if (pos < k){

        }
    }
    return ans;
}

int main(){
    int n, k;
    cin >>n >>k;
    cout <<binarySearch(n, k) <<endl;
    return 0;
}