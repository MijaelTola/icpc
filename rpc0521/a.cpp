#include <bits/stdc++.h>

using namespace std;

const int NEUTRO = 0;

struct SegmentTree{
    int st[500010];
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
bool vis[150100];
int nchain; //chains number
int depth[150100];//Depth of the node
int chain[150100];// chain i th node belongs // Also remark the head of the chain
int sizetree[150100]; // node s number on subtree below
int parent[150100]; // paren i th node
int idx[150100]; //position on ST
int A[150100];
int pos = -1;
vector<int> G[150100];

void clean(){
    for (int i = 0; i < 150100; ++i){
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
    int id = -1;
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

int values[1000100];
int k;
// this HLD is 0-indexed
int main(){
    //ios::sync_with_stdio(false); cin.tie(0);
        clean();
        
        cin >> n >> k;
        for (int i = 0; i < k; ++i) 
            cin >> values[i];


        for (int i = 1; i <= n - 1; ++i) {
            int x;
            cin >> x;
            G[x].push_back(i);
            G[i].push_back(x);
        }
        pos = -1;
        nchain = 1;
        depth[0]  = 0;
        parent[0] = -1;
        vis[0] = true;
        dfs(0);
        hld(0,0);

        map<int,int> mp;
        for (int i = 0; i < n; ++i) {
            mp[chain[i]]++;
        }

        vector<int> res;
        for (auto [a,b]: mp) {
            res.push_back(b);
        }

        sort(res.rbegin(), res.rend());
    
        sort(values, values + k);
        reverse(values, values + k);

        long long ans = 0;

        for (int i = 0; i < (int)res.size(); ++i) {
            ans += values[i] * res[i];
        }

        cout << ans - values[0] << "\n";



    return 0;
}
