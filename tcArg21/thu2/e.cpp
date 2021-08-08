#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> G[100010];
int ans = 0;

int f(int u, int p = -1) {
    int cur = 1;
    for (int v: G[u]) {
        if(p != v) cur += f(v, u);
    }

    if(cur % 2 == 0 and cur > 0) {
        ans++;
        return 0;
    }

    return cur;
}

int main() {

    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    if(n & 1) 
        return cout << "-1\n", 0;

    f(1);
    cout << ans - 1 << "\n";
    return 0;
}

