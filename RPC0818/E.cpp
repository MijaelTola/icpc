#include <bits/stdc++.h>

using namespace std; 

int n,b,c,cur;
bool vis[10010];
int cost[10010],pres[10010];
int dp[10010][10010];
vector<pair<int, pair<int,int > > > G[10010];
unordered_map<string,int> mp;

void dfs(int u) {
    for (pair<int, pair<int,int> > p: G[u]) {
        int v = p.first;
        int dc = cost[u] + p.second.first;
        int dp = pres[u] + p.second.second;
        if(dc < cost[v] or (dc == cost[v] and dp > pres[v])) {
            cost[v] = dc;
            pres[v] = dp;
            dfs(v);
        }
    }
}

int f(int pos, int budget) {
    if(pos == c or budget == 0) return 0;
    if(dp[pos][budget] != -1) return dp[pos][budget];
    int ans = 0;
    if(budget - cost[pos] >= 0)  
        ans = max(ans,f(pos + 1, budget - cost[pos]) + pres[pos]);
    ans = max(ans, f(pos + 1, budget));
    return dp[pos][budget] = ans;
}

void r(int pos, int budget) {
    if(pos == c or budget == 0) return;
    int ans1 = 0;
    int ans2 = 0;
    if(budget - cost[pos] >= 0)  
        ans1 = f(pos + 1, budget - cost[pos]) + pres[pos];
    ans2 = f(pos + 1, budget);
    if(ans1 > ans2) {
        cur += cost[pos];
        r(pos + 1, budget - cost[pos]);
        return;
    } 
    
    r(pos + 1, budget);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(vis, false, sizeof vis);
    memset(dp, -1,sizeof dp);
    c = cur = 0;
    for (int i = 0; i < 10010; ++i) {
        pres[i] = 0;
        cost[i] = 1e9;
    }
    cin >> b >> n;
    for (int i = 0; i < n; ++i) {
        string x,y,z;
        int dc,p;
        cin >> x >> y >> z >> dc >> p;
        if(!mp.count(x)) mp[x] = c++;
        if(!mp.count(y)) mp[y] = c++;
        G[mp[y]].push_back({mp[x],{dc,p}});
        vis[mp[x]] = 1;
    }
    
    for (int i = 0; i < c; ++i)
        if(!vis[i]) {
            cost[i] = 0;
            dfs(i);
        }
     
    int ans = 0;
    int a = 0;
    for (int i = 0; i <= b; ++i) {
        int cur = f(0,i);
        if(cur > ans) {
            ans = cur;
            a = i;
        }
    }
    cout << ans << "\n";
    cout << a << "\n";
    return 0;
}
