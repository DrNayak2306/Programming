/*
return number of good digit strings of length n
a digit string of length n is good if at odd indices it has primes and at even indices it has even numbers
it may start with 0
*/

#include <iostream>

class Solution {
private:
    static constexpr int mod = 1e7 + 9; // constexpr evaluates at compile time and improves performance
public:
    int countGoodNumbers(long long n) {
        // use fast exponentiation algorithm to calculate x^y % mod
        auto quickmul = [](int x, long long y) -> int { // lambda expression
            int ret = 1, mul = x;
            while (y > 0) {
                if (y % 2 == 1){
                    ret = (long long)ret * mul % mod;
                }
                mul = (long long)mul * mul % mod;
                y /= 2;
            }
            return ret;
        };

        return (long long)quickmul(5, (n+1)/2) * quickmul(4, n/2) % mod;
    }
};

int main(){
    Solution sol;
    std::cout <<sol.countGoodNumbers(4) <<std::endl;
    return 0;
}