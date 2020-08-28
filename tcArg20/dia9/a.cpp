#include <bits/stdc++.h>

using namespace std;

vector<int> G[100010];
int color[100010];

void dfs(int u, int turn, int p = -1) {
    if(color[u] != -1) return;
    color[u] = turn;
    for (int v: G[u]) 
        if(v != p) dfs(v, 1 - turn, u);
}
int main() {
    memset(color, -1, sizeof color);
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(1, 1);
    long long a = 0, b = 0;

    for (int i = 1; i <= n; ++i)
        if(color[i]) a++;
        else b++;

    cout << a * b - (n - 1) << "\n";

    return 0;
}

