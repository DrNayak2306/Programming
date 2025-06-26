/*
builtin functions of GCC:
__builtin_popcount()
__builtin_parity() // true for odd number of set bits
__builtin_clz() // count leading zeros
__builtin_ctz() // count trailing zeros
*/

/*
given an n array of values, determine if W can be formed
*/

#include <bits/stdc++.h>
#define MAX_W (long long)1e6
using namespace std;


void usual(){
    bool exists[MAX_W];
    int n, W;
    cin >>n >>W;
    exists[0] = true;
    
    while (n--) {
        int x;
        cin >>x;
        // value x exists, so for every existing y, y + x exists
        // WARNING: carry out update from right to left (updated region must not be checked)
        // O(N*W)
        for (int i = W-x; i >= x; i--)
            if (exists[i]) exists[i+x] = true;
    }
    cout <<(exists[W] ? "YES" : "NO") <<"\n";
}

void optimal(){
    int n, W;
    cin >>n >>W;
    bitset<MAX_W> exists;
    exists[0] = true;

    int i = 1;
    while (n--) {
        int x;
        cin >>x;
        // essentially, we must shift all true bits by x, and update the exists
        // O(N * W / machine word size)
        exists |= (exists << x);
    }
    for (int i=0; i<W; i++) cout <<exists[i];
    cout <<(exists[W] ? "YES" : "NO") <<"\n";
}

int main(){
    optimal();
    return 0;
}