#include <bits/stdc++.h>

using namespace std;

int dp[100010];
int t[100010];
int sum[100010];
int sum2[100010];
int sum3[100010];
int depth[100010];
int ans[100010];

int csum[100010];
int csum3[100010];

vector<pair<int,int> > G[100010];

void dfs(int u, int pr = -1) {
    depth[u] = 1;
    sum2[u] = t[u];
    for (auto p: G[u]) {
        int v = p.first;
        int w = p.second;
        if(v == pr) continue;
        dfs(v, u);
        sum3[u] += sum3[v];
        sum3[u] += w * sum2[v];
        sum2[u] += sum2[v];
        sum[u] += w * depth[v];
        sum[u] += sum[v];
        depth[u] += depth[v];
    }
    dp[u] = t[u] * sum[u] + sum3[u];
}

void dfs2(int u,int pr = -1) {

    ans[u] = t[u] * (sum[u] + csum[u]) + sum3[u] + csum3[u];
    
    for (auto p: G[u]) {
        int v = p.first;
        int w = p.second;
        if(v == pr) continue;
        
        cout << sum[u] - sum[v] << "\n";
        exit(0);
        sum[v] +=  (sum[u] - sum[v]) + w * (depth[u] - depth[v]);
        sum3[v] += (sum3[u] - sum3[v]) + w * (sum2[u] - sum2[v]);
     
        dfs2(v, u);
    }

}

int main() {
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> t[i];

    for (int i = 0; i < n - 1; ++i) {
        int x,y,w;
        cin >> x >> y >> w;
        G[x].push_back({y, w});
        G[y].push_back({x, w});
    }

    dfs(1);
    dfs2(1);

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << "\n";

    return 0;
}

//2 - 4 = 45 
//2 - 3 = 64
//2 - 5 = 36
