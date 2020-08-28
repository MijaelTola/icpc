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
    ll st[100010*2];
    int n;
    void init(int nn){n = nn; memset(st,0,sizeof st);}
    void update(int pos, int value){
        for (st[pos += n] = value; pos > 1; pos >>= 1)
            st[pos>>1] = st[pos] + st[pos^1];
    }
    //ST [l,r)
    ll query(int l, int r){
        ll ans = NEUTRO;
        r++; 
        for (l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) ans += st[l++];
            if(r&1) ans += st[--r];
        }
        return ans;
    }
    int pos(int x){return st[x+=n];}
};

struct SegmentTreeMax{
    ll st[100010*2];
    int n;
    void init(int nn){n = nn; memset(st,0,sizeof st);}
    void update(int pos,int value){
        for (st[pos+=n] = value; pos > 1; pos>>=1)   
            st[pos>>1] = max(st[pos],st[pos^1]);
    }
    ll query(int l, int r){
        ll ans = 0;
        r++;
        for (l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) ans = max(ans,st[l++]);
            if(r&1) ans = max(ans,st[--r]);
        }
        return ans;
    }
    ll pos(int i){
        return st[i];
    }
};
SegmentTree ST;
SegmentTreeMax STmx;
int n;
bool vis[101000];
int nchain; //chains number
int depth[101000];//Depth of the node
int chain[101000];// chain i th node belongs // Also remark the head of the chain
int sizetree[100100]; // node s number on subtree below
int parent[100100]; // paren i th node
int idx[100010]; //position on ST
int value1[100010];
int value2[100010];
int A[10100];
int pos = -1;
vector<pair<int,pair<int,int> > > G[100100];
typedef pair<int,pair<int,int> > ii;
//preprocess depth, sizeSubtree and parent
int dfs(int u){
    sizetree[u] = 1;
    for(ii v: G[u]){
        if(!vis[v.first]){
            vis[v.first] = true;
            parent[v.first] = u;
            depth[v.first] = depth[u]+1;
            sizetree[u] += dfs(v.first);
        }
    }
    return sizetree[u];
}

//Start heavy light descomposition
//Process chains and positions on ST
void hld(int u, int ch, int hrd, int lnt){
    chain[u] = ch;
    idx[u] = ++pos;
    value1[u] = hrd;
    value2[u] = lnt;
    int id;
    int mx = -1, h1 = -1, l1 = -1;
    for (ii e: G[u]){
        int v = e.first; int h = e.second.first;
        int l = e.second.second;
        if(v != parent[u] and sizetree[v] > mx){
            mx = sizetree[v];
            id = v;
            h1 = h;
            l1 = l;
        }
    }
    if(mx != -1) hld(id,ch,h1,l1);
    for (ii e:G[u]){
        int v = e.first; int h = e.second.first;
        int l = e.second.second;
        if(v != parent[u] and v != id){
            nchain++;
            hld(v,v,h,l);
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
pair<ll,ll> walkUp(int from,int lca){
    ll ans = NEUTRO;
    ll mx = NEUTRO;
    while(chain[from] != chain[lca]){
        ans +=ST.query(idx[chain[from]],idx[from]); //process gcd(from to head of from)
        mx = max(mx,STmx.query(idx[chain[from]],idx[from]));
        from = parent[chain[from]]; //change chain
    }
    return  {ans+ST.query(idx[lca]+1,idx[from]),max(mx,STmx.query(idx[lca]+1,idx[from]))};  
}

// this HLD is 1-indexed
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; ++i){
        int x,y,r,s; cin >> x >> y >> r >> s;
        G[x].push_back({y,{r,s}});
        G[y].push_back({x,{r,s}});
    }
    nchain = 1;
    depth[1]  = 0;
    parent[1] = -1;
    vis[1] = true;
    dfs(1);
    hld(1,1,-1,-1);
    ST.init(pos);
    STmx.init(pos);
    for (int i = 1; i <= n; ++i) STmx.update(idx[i],value1[i]),ST.update(idx[i],value2[i]);
    int q; cin >> q;
    while(q--){
        int x,y; cin >> x >> y;
        int lca = LCA(x,y);
        pair<ll,ll> A = walkUp(x,lca);
        pair<ll,ll> B = walkUp(y,lca);
        ll ans1 = A.first + B.first;
        ll ans2 = max(A.second,B.second);
        cout << ans1* ans2 << "\n";
    }
    return 0;
}
