#include <bits/stdc++.h>

using namespace std;

vector<int> G[1010];
bool vis[1010];

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for (int v: G[u])
        dfs(v);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n and n) {
        vector<pair<long long, long long> > v;

        memset(vis, 0, sizeof vis);

        for (int i = 0; i < n; ++i)
            G[i].clear();

        for (int i = 0; i < n; ++i) {
            long long x,y;
            cin >> x >> y;
            v.push_back({x,y});
        }

        auto dis = [&] (pair<long long, long long> a, pair<long long, long long> b) {
            return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
        };

        for (int i = 0; i < n; ++i) {
            vector<tuple<int,int,int, int> > b;
            for (int j = 0;j  < n; ++j) {
                if(i == j) continue;
                b.push_back({dis(v[i], v[j]), v[j].first, v[j].second, j});
            }

            sort(b.begin(), b.end());
            int a,l,c,d;
            tie(a,l,c,d) = b[0];
            G[i].push_back(d);
            tie(a,l,c,d) = b[1];
            G[i].push_back(d);
        }


        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            if(!vis[i]) {
                cnt++;
                dfs(i);
            }
        }

        if(cnt != 1) cout << "Chapare no Protegido\n";
        else cout << "Chapare protegido\n";
    }
    return 0;
}

