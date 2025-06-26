/*
count the number of triangles in a graph
*/

#include <bits/stdc++.h>
#define MAX_N 2000
using namespace std;


void usual(){
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<unordered_set<int>> graph(n+1);
    int node = 0;
    string s;
    while (getline(cin, s)){
        stringstream ss(s);
        int node, x;
        ss >> node;
        while (ss >> x) graph[node].insert(x);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (graph[i].contains(j) && graph[i].contains(k) && graph[j].contains(k)){
                    cnt++;
                }
            }
        }
    }
    cout << cnt <<endl;
}

void optimal(){
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<bitset<MAX_N>> mask(n+1);
    string line;
    while (getline(cin, line)){
        stringstream s(line);
        int u, v;
        s >> u;
        while (s >> v) mask[u][v] = 1;
    }
    int cnt = 0;
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            cnt += mask[u][v] * (mask[u] & mask[v]).count();
        }
    }
    cout <<"Optimal solution: ";
    cout << cnt / 3 << endl;
}

int main(int argc, char *argv[]){
    cout << argv[1] <<endl;
    if (strcmp(argv[1], "usual") == 0) usual();
    else optimal();
    return 0;
}