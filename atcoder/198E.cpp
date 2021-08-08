#include <bits/stdc++.h>

using namespace std;

int c[100010];
vector<int> G[100010];
multiset<int> s;
vector<int> ans;

void f(int u, int p = -1) {
    
    if(!s.count(c[u])) ans.push_back(u);
    s.insert(c[u]);
    for (auto v: G[u]) {
        if(v != p) f(v, u);
    }

    s.erase(s.lower_bound(c[u]));
}


int main() {
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> c[i];

    for (int i = 0; i < n - 1; ++i) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    f(1);

    sort(ans.begin(), ans.end());
    for (auto x: ans)
        cout << x << "\n";
    return 0;
}

