#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dis[2*200100];
int L[2*200100];
int E[2*200100];
int H[2*200100];
bool vis[200100];
int table[2*200100][1000];
vector<pair<int,int> > G[20100]; // Graph with weight
int idx;

// Sparse Table 
// Preprocess 
void build(int n){
    for (int i = 0; i < n; ++i) table[i][0] = i;
    for (int j = 1; (1<<j) <= n; ++j){
        for (int i = 0; i + (1<<j)-1 < n; ++i){
            if(L[table[i][j-1]] < L[table[i+(1<<(j-1))][j-1]])
                table[i][j] = table[i][j-1];
            else table[i][j] = table[i+(1<<(j-1))][j-1];
        }
    }
}

// query [l, e] O(1)
int query(int i, int j){
    int k = (int)floor(log((double)j-i+1)/log(2.0));
    if(L[table[i][k]] <= L[table[j-(1<<k)+1][k]])
        return table[i][k];
    else
        return table[j-(1<<k)+1][k];
}

// construct vectors H E L 
void dfs(int cur, int depth){
    //  assert(cur >= 0 and cur < 100010);
    H[cur] = idx;
    E[idx]= cur;
    L[idx++] = depth;
    for (pair<int,ll> u: G[cur]){
        if(!vis[u.first]){
            vis[u.first] = true;
            dis[u.first] = dis[cur]+u.second;
            dfs(u.first,depth+1);
            E[idx] = cur;
            L[idx++] = depth;
        }
    }
}

int main(){
    int n; 
    // while(scanf("%d",&n)){
    scanf("%d",&n);
    // if(n == 0) break;
    /*for (int i = 0; i < 50100; ++i){
      H[i] = -1;
      G[i].clear();
      vis[i] = false;
      }*/
    memset(vis,0,sizeof vis);
    memset(H, -1, sizeof H);
    for(int i = 1; i < n; ++i){
        int x,y; scanf("%d %d",&x,&y);
        G[x - 1].push_back({y - 1,1});
        G[y - 1].push_back({x - 1,1});
    }
    idx = 0;
    dis[0] = 0;
    vis[0] = true;
    dfs(0,0);
    build(idx);
    long long ans = 0;
    for (int i = 1; i <= n / 2; ++i) {
        int c = i + i;
        while(c <= n) {
            int px = H[i - 1];
            int py = H[c - 1];
            if(px > py) swap(px,py);
            int lca =  E[query(px,py)];
            int d = dis[lca];
            int dx = dis[i - 1];
            int dy = dis[c - 1];
            ans += (dx + dy - 2 * d) + 1;
            //cout << i << " -> " << c << " = " << (dx + dy - 2 * d) + 1 << "\n";
            c += i;
        }
    }
    cout << ans << "\n";
    /*
     * int q; scanf("%d",&q);
     while(q--){
     int x,y;
     scanf("%d %d",&x,&y);
     int px = H[x];
     int py = H[y];
     if(px > py) swap(px,py);
     int lca =  E[query(px,py)];
     ll d = dis[lca];
     ll dx = dis[x];
     ll dy = dis[y];
     printf("%lld\n",dx+dy-2*d);
     }*/
    return 0;
}

