#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>

using namespace std;

typedef long long ll;
const int NEUTRO = 0;
struct SegmentTree{
    int st[100000];
    int n;
    void init(int nn){n = nn; memset(st,0,sizeof st);}
    void update(int pos, int value){
        for (st[pos += n] = value; pos > 1; pos >>= 1)
            st[pos>>1] = __gcd(st[pos],st[pos^1]);
    }
    //ST [l,r)
    int query(int l, int r){
        int ans = NEUTRO;
        r++; 
        for (l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) ans = __gcd(ans,st[l++]);
            if(r&1) ans = __gcd(ans,st[--r]);
        }
        return ans;
    }
    int pos(int x){return st[x+=n];}
};

SegmentTree ST;
int n;
bool vis[50100];
int nchain; //chains number
int depth[50100];//Depth of the node
int chain[50100];// chain i th node belongs // Also remark the head of the chain
int sizetree[50100]; // node s number on subtree below
int parent[50100]; // paren i th node
int idx[50100]; //position on ST
int A[50100];
int pos = -1;
vector<int> G[50100];

void clean(){
    for (int i = 0; i < 50100; ++i){
        vis[i] = false;
        depth[i] = 0;
        chain[i] = 0;
        sizetree[i] = 0;
        idx[i] = 0;
        A[i] = 0;
        G[i].clear();
    }
}
//preprocess depth, sizeSubtree and parent
int dfs(int u){
    sizetree[u] = 1;
    for(int v: G[u]){
        if(!vis[v]){
            vis[v] = true;
            parent[v] = u;
            depth[v] = depth[u]+1;
            sizetree[u] += dfs(v);
        }
    }
    return sizetree[u];
}

//Start heavy light descomposition
//Process chains and positions on ST
void hld(int u, int ch){
    chain[u] = ch;
    idx[u] = ++pos;
    int id;
    int mx = -1;
    for (int v: G[u]){
        if(v != parent[u] and sizetree[v] > mx){
            mx = sizetree[v];
            id = v;
        }
    }
    if(mx != -1) hld(id,ch);
    for (int v:G[u]){
        if(v != parent[u] and v != id){
            nchain = 0;
            hld(v,v);
        }
    }
}

int LCA(int x,int y){
    while(chain[x] != chain[y]){
        if(depth[chain[x]] > depth[chain[y]]) x = parent[chain[x]];
        else y = parent[chain[y]];
    }
    if(depth[x] < depth[y]) return x;
    return y;
}

//going up to lca
int walkUp(int from,int lca){
    int ans = NEUTRO;
    while(chain[from] != chain[lca]){
        ans = __gcd(ans,ST.query(idx[chain[from]],idx[from])); //process gcd(from to head of from)
        from = parent[chain[from]]; //change chain
    }
    return __gcd(ans,ST.query(idx[lca],idx[from]));
}

// this HLD is 0-indexed
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> n){
    clean();
    for(int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n-1; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    pos = -1;
    nchain = 1;
    depth[0]  = 0;
    parent[0] = -1;
    vis[0] = true;
    dfs(0);
    hld(0,0);
    ST.init(pos);
    for (int i = 0; i < n; ++i) ST.update(idx[i],A[i]);
    int q; cin >> q;
    while(q--){
        int c,x,y; cin >> c >> x >> y;
        if(c == 1){
            int lca = LCA(x,y);
            cout << __gcd(walkUp(x,lca),walkUp(y,lca)) << "\n";
        }else ST.update(idx[x],y);
    }
    }
    return 0;
}

