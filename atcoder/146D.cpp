#include <bits/stdc++.h>

using namespace std;

vector<int> G[100010];
vector<pair<int,int> > e;
map<pair<int,int>, int> mp;
int ans[100010];
int in[100010];
int mx;

void dfs(int u, int p, int color) {
    ans[u] = color;
    mp[make_pair(min(u,p), max(u,p))] = color;
    set<int> s;
    if(color != 0)s.insert(color);
    int cur = 1;
    for (int v: G[u]) {
        if(v == p) continue;
        while(s.count(cur) and cur <= mx) cur++;
        s.insert(cur);
        dfs(v, u, cur);
    }
}

int main() {
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        e.emplace_back(min(x,y), max(x,y));
        in[x]++,in[y]++;
    }

    mx = 0;
    for (int i = 1; i <= n; ++i)
        mx = max(mx, in[i]);

    dfs(1,1,0);
    
    cout << mx << "\n";

    for (auto p: e) 
        cout << mp[make_pair(p.first, p.second)] << "\n";
    return 0;
}

