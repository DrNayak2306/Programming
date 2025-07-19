#include <bits/stdc++.h>

using namespace std;
template<class t>
class hash {
public:
    hash(t x) {
        val = x;
    }
private:
    t val;
};
int main(){
    ::hash<int> a(1);
    return 0;
}