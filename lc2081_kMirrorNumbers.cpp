#include <bits/stdc++.h>

using namespace std;

class Solution{
private:
    int digit[100];
public:
    long long mirrorK (int k, int n) {
        auto isPalindrome = [&](long long x) -> bool {
            int length = 0;
            while (x) {
                digit[length] = x % k;
                x /= k;
                length++;
            }
            for (int i = 0, j = length-1; i < j; i++, j--)
                if (digit[i] != digit[j])
                    return false;
            return true;
        };
        
        int next, cur = 1;
        int count = 0;
        long long ans = 0;
        while (count < n){
            next = cur * 10;
            for (char op = 1; op <= 2; op++) {
                for (int i = cur; i < next && count < n; i++){
                    int x = (op == 1) ? i/10 : i;
                    long long number = i;
                    while (x) {
                        number = number * 10 + x % 10;
                        x /= 10;
                    }
                    if (isPalindrome(number)){
                        count++;
                        ans += number;
                    }
                }
            }
            cur = next;
        }
        return ans;
    }
};

int main(){
    Solution obj;
    int k, n;
    freopen("input.txt", "r", stdin);
    while (cin >> k && cin >> n) {
        cout << obj.mirrorK(k, n) <<endl;
    }
    return 0;
}