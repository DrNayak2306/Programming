/*
find the kth smallest number in the lexicographical ordering of numbers 1..n
*/

#include <iostream>

using namespace std;

int position(int n, int x){
    int cnt = 0;
    int msd = x;
    while (msd > 9){
        msd /= 10;
    }
    // cout <<"msd: " <<msd <<"\n";
    for (int i = 1; i <= 9 && i <= msd; i++){
        int startCnt = 0,
            check = i,
            base = 1;

        while (check < n){
            if (i == x/base) break;
            cout <<check <<" ";
            if (check < x)
                startCnt += base;
            else startCnt++;
            base *= 10;
            check = i * base;
        }
        if (i == msd && i == x/base){
            // cout <<check <<" ";
            startCnt += x - check + 1;
        }
        cout <<"\t" <<startCnt<<"\t";
        cnt += startCnt;
    }
    
    return cnt;
}

int binarySearch(int n, int k){
    int low = 1, high = 9, mid;
    int ans = -1;
    while (low <= high){
        mid = (low + high)/2;
        int pos = position(n, mid);
        if (pos == k){
            ans = mid;
            break;
        } else if (pos < k){
            if (position(n, mid+1) < k)
                low = mid+1;
            else{
                low *= 10;
                low = min(low, mid);
                high = max(low, mid);
            }
        } else{
            int high = mid-1;
            while (high*10 <= n)
                high *= 10;
        }
    }
    return ans;
}

int main(){
    // int n, k;
    // cin >>n >>k;
    int n = 11;
    for (int i=1; i<=n; i++)
        cout <<i <<": " <<position(n, i) <<endl;
    return 0;
}