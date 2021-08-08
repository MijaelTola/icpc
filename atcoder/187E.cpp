#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > e;
vector<int> G[200010];
int p[200010];
long long ac[200010];
long long cur = 0;
long long ans[200010];

void dfs(int u, int pt = 0) {
    p[u] = pt;
    for (int v: G[u]) {
        if(v != pt) dfs(v, u);
    }
}

void f(int u, int pt = 0, long long sum = 0) {
    sum += ac[u];
    ans[u] = sum;
    for (int v: G[u]) {
        if(v != pt) f(v, u, sum);
    }
}

int main() {

    cin >> n;
    
    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        e.push_back({x,y});
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(1);
    
    int q;
    cin >> q;

    while(q--) {
        int t, ee, x;
        cin >> t >> ee >> x;
        auto [a,b] = e[ee - 1];

        if(t == 1) {
            if(p[a] != b) {
                ac[1] += x;
                ac[b] -= x;
            } else {
                ac[a] += x;
            }
        } else {
            if(p[b] != a) {
                ac[1] += x;
                ac[a] -= x;
            } else {
                ac[b] += x;
            }
        }

    }
    
    f(1);
    for (int i = 1; i <= n; ++i)
        cout <<ans[i] << "\n";

    return 0;
}

