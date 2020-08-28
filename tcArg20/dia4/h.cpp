#include <bits/stdc++.h>

using namespace std;

vector<int> G[10010];

int dfs(int u, int p = -1) {
    
    for (int v: G[u]) {
        
    }
}

int main() {

    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        G[x].push_back(i);
    }
    return 0;
}

