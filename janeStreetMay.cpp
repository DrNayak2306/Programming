#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<char>> layout;
    vector<vector<int>> grid;
    unordered_map<char, int> segVal;
    set<pair<int, int>> tiles;
    
public:
    void setVal(char ch, int val) {
        segVal[ch] = val;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (layout[r][c] == ch) {
                    grid[r][c] = val;
                }
            }
        }
    }
    
    long long getRowNum(int row) {
        long long n = 0;
        long long base = 1;
        for (int col = grid[0].size()-1; col >= 0; col--) {
            if (tiles.find({row, col}) != tiles.end()) {
                continue;
            }
            if (grid[row][col] < '0' || grid[row][col] > '9') {
                return -1;
            }
            n += base * segVal[layout[row][col]];
            base *= 10;
        }
        return n;
    }

    bool isGoalState() {
        // is a square
        long long n;
        if ((n = getRowNum(0)) == -1) return false;
        int rt = sqrt(n);
        if (1LL * rt * rt != n) return false;
        
        // product of digits is 20
        if ((n = getRowNum(1)) == -1) return false;
        int prod = 1;
        while (n && prod < 20) {
            int d = n % 10;
            prod *= d;
            n /= 10;
        }
        if (prod != 20) return false;

        // multiple of 13
        if ((n = getRowNum(2)) == -1 || n % 13 != 0) return false;

        // multiple of 32
        if ((n = getRowNum(3)) == -1 || n % 32 != 0) return false;

        // divisible by each of its digits
        if ((n = getRowNum(5)) == -1) return false;
        for (int x = n; x > 0; x /= 10) {
            int d = x % 10;
            if (d == 0 || n % d != 0) {
                return false;
            }
        }

        // product of digits is 25
        if ((n = getRowNum(5)) == -1) return false;
        int prod = 1;
        while (n && prod < 25) {
            int d = n % 10;
            prod *= d;
            n /= 10;
        }
        if (prod != 25) return false;

        // divisible by each of its digits
        if ((n = getRowNum(6)) == -1) return false;
        for (int x = n; x > 0; x /= 10) {
            int d = n % 10;
            if (d == 0 || n % d != 0) {
                return false;
            }
        }

        // odd and a palindrome
        n = getRowNum(7);
        if (n % 2 == 0) {
            return false;
        }

        long long rev = 0;
        for (int x = n; x > 0; x /= 10) {
            rev += x % 10;
            rev *= 10;
        }
        if (rev != n) return false;

        // is fibonacci
        n = getRowNum(8);
        long long a = 1, b = 1, c;
        while ((c = a + b) < n) {
            a = b;
            b = c;
        }
        if (c != n) return false;

        // product of digits is 2025
        n = getRowNum(9);
        int prod = 1;
        
        while (n && prod < 2025) {
            int d = n % 10;
            prod *= d;
            n /= 10;
        }
        if (prod != 2025) return false;

        // prime
        n = getRowNum(10);
        if (n < 2) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    
public:
    Solution (string fileName) {
        ifstream fin(fileName);
        string line;
        while (getline(fin, line)) {
            stringstream ln(line);
            string s;
            layout.push_back({});
            grid.push_back({});
            while (ln >> s) {
                char ch = s[0];
                layout.back().push_back(ch);
                grid.back().push_back(0);
            }
        }
    }

    void displayLayout() {
        for (int r = 0; r < layout.size(); r++) {
            for (int c = 0; c < layout[0].size(); c++) {
                cout << layout[r][c] << " ";
            }
            cout << "\n";
        }
    }

    void solve() {

    }
};

int main(){
    Solution obj("janeStreetMay.txt");
    obj.displayLayout();
    obj.setVal('a', 0);
    obj.setVal('A', 1);
    obj.setVal('b', 5);
    cout << obj.getRowNum(1) << endl;
    cout << (obj.isGoalState()) << endl;
    return 0;
}