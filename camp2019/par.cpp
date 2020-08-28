#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> G[500010];
int d[500010];
int D[500010];
int dp[500010][3];

void dfs(int u, int p) {
    d[u] = 1;
    for (int v: G[u]) {
        if(v == p) continue;
        dfs(v,u);
        d[u] += d[v];
    }
}


int f(int u, int p, int flag) {
    int &ans = dp[u][flag];
    if(ans != -1) return ans;
    ans = 0;
    int mx = -1, mx2 = -1;
    for (int v: G[u]) {
        if(v == p) continue;
        if(!flag) {
            ans = max(ans, f(v, u, flag));
            if(f(v, u, flag) > mx) {
                mx2 = mx;
                mx = f(v,u,flag);
            }
            ans = max(ans, f(v, u, 1) + (int)G[u].size() - (1 + (v == 1)));

            if(f(v, u, 1) + (int) G[u].size() - (1 + (v == 1)) > mx) {
                mx2 = mx;
                mx = f(v, u, 1) + (int) G[u].size() - (1 + (v == 1));
            }

        } else {
            ans = max(ans, f(v, u, flag) + (int)G[u].size() - 2);
            if(f(v, u, flag) + (int) G[u].size() - 2 > mx) {
                mx2 = mx;
                mx = f(v, u, flag) + (int) G[u].size() - 2 ; 
            }
            ans = max(ans, (int)G[v].size() - 1);
            if((int)G[v].size() - 1 > mx) {
                mx2 = mx;
                mx = G[v].size() - 1; 
            }
        }
    }
    ans = max(ans, mx + mx2 + 2);
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    G[0].push_back(1);
    dfs(0,0);
    cout << f(0,0,0) << "\n";
    return 0;
}
