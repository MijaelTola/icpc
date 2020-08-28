#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> G[100010];
bool vis[100010];
int way[100010];
long long dp[100010];

void pre(int u, int p, int x) {
    vector<int> d;
    dp[u] = 0;
    if(u != x) {
        for (int v: G[u]) {
            if(v == p or x == v) continue;
            pre(v,u,x);
            d.push_back(dp[v]);
        }
    }
    sort(d.rbegin(), d.rend());
    for (int i = 0; i < (int)d.size(); ++i) 
        dp[u] = max(dp[u], (long long)d[i] + (i + 1));

}

int main() {
    int n,type;
    cin >> n >> type;
    int a,b;
    cin >> a;
    if(type == 2) cin >> b;

    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }


    if(type == 1) {
        pre(a,a, 0);
        cout << dp[a] << "\n";
        return 0;
    }

    memset(way, -1, sizeof way);
    queue<int> q;
    q.push(a);
    way[a] = a;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        if(u == b) break;
        for (int v: G[u]) {
            if(!vis[v]) {
                way[v] = u;
                q.push(v);
            }
        }
    }
    vector<int> path;
    int pb = b;
    path.push_back(b);
    while(pb != way[pb]) {
        pb = way[pb];
        if(pb != way[pb])path.push_back(pb);
    }
    path.push_back(a);
    reverse(path.begin(), path.end());
    
    int l = 0, r = path.size() - 1;
    int dl = 1,dr = 1;
    while(r - l > 1) {
        int mid = (r + l) / 2;
        pre(a, a, path[mid]);
        dl = dp[a];
        pre(b, b, path[mid - 1]);
        dr = dp[b];
        //cout << dl << " " << dr << " " << path[mid]<< " test\n";
        if((dl - dr) <= 0) l = mid;
        else r = mid;
    }
    //if(l == 0) l++;
    //if(r >= (int)path.size() -1) r--;
    //cout << path[l] << " " << path[r] << " last\n";
    if(l == -1 and r == (int)path.size()) {
        pre(a, a, b);
        int a1 = dp[a];
        pre(b, b, a);
        int a2 = dp[b];
        int mx = max(a1, a2);
        cout << mx << "\n";
        return 0;
    }
    int a1,a2;
    pre(a,a,path[r]);
    a1 = dp[a];
    pre(b,b,path[r - 1]);
    a2 = dp[b];
    int mx = max(a1, a2);
    pre(a,a,path[l]);
    a1 = dp[a];
    pre(b,b,path[l - 1]);
    a2 = dp[b];
    mx = min(mx, max(a1,a2));
    cout << mx << "\n";
    return 0;
}

