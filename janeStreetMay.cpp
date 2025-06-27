#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<char>> layout;
    vector<vector<int>> grid;
    unordered_map<char, int> segVal;
    
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
            n += base * segVal[layout[row][col]];
            base *= 10;
        }
        return n;
    }
    inline bool row1() {
        long long n = getRowNum(0);
        int rt = sqrt(n);
        return 1LL * rt * rt == n;
    }

    inline bool row2() {
        // product of digits is 20
    }
    inline bool row3() {
        // multiple of 13
    }
    inline bool row4() {
        // multiple of 32
    }
    inline bool row5() {
        // divisible by each of its digits
    }
    inline bool row6() {
        // product of digits is 25
    }
    inline bool row7() {
        // divisible by each of its digits
    }
    inline bool row8() {
        // odd and a palindrome
    }
    inline bool row9() {
        // fibonacci
    }
    inline bool row10() {
        // product of digits is 2025
    }
    inline bool row11() {
        // prime
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
};

int main(){
    Solution obj("input.txt");
    obj.displayLayout();
    obj.setVal('a', 0);
    cout << obj.getRowNum(0) << endl;
    cout << obj.row1() << endl;
    return 0;
}