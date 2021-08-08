#include <bits/stdc++.h>

using namespace std;

int n,m,qr;
vector<int> G[1000010];
int out[1000010];
long long uno[1000010];
long long todos[1000010];
long long total[1000010];
long long thijos[1000010];
long long lazy[1000010];
int p[1000010];
int cnt[1000010];

long long f(int u, int p = -1) {
    long long ans = total[u];
    for (int v: G[u]) 
        if(p !=  v) ans += f(v, u);
    return thijos[u] = ans;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> qr;

    int root = -1;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if(x == 0) root = i;
        else {
            G[x].push_back(i);
            p[i] = x;
            out[x]++;
        }
    }

    for (int i = 0; i < m; ++i) {
        int t,e,v;
        cin >> t >> e >> v;
        if(t == 1) {
            uno[e] += v;
        } else {
            todos[e] += v;
        }
    }


    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if(out[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        lazy[u] += todos[u];
        total[u] += uno[u] + lazy[u];
        if(p[u]) {
            cnt[p[u]]++;
            lazy[p[u]] += lazy[u];
            if(cnt[p[u]] == (int)G[p[u]].size())
                q.push(p[u]);
        }
    }
    

    f(root);

    while(qr--) {
        int t,e;
        cin >> t >> e;
        if(t == 1) cout << total[e] << "\n";
        else cout << thijos[e] << "\n";
    }

    return 0;
}

