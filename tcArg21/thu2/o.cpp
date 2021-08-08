#include <bits/stdc++.h>

using namespace std;

vector<int> G[1000010];
vector<int> GT[1000010];
stack<int> s;
bool vis[1000010];
int scc[1000010];

void dfs(int u){
    for (int i = 0; i < (int)G[u].size(); ++i){
        int v = G[u][i];
        if(!vis[v]){
            vis[v] = true;
            dfs(v);
        }
    }
    s.push(u);
}

void dfs2(int u, int num){
    for (int i = 0; i < (int)GT[u].size(); ++i){
        int v = GT[u][i];
        if(scc[v] == -1){
            scc[v] = num;
            dfs2(v,num);
        }
    }
}

int no(int p){
    return (p < 200001) ? p + 200001 : p - 200001;
}

void kosaraju(){
    memset(vis,false,sizeof vis);
    memset(scc,-1,sizeof scc);
    for (int i = 0; i < 1000010; ++i){
        if(!vis[i]) dfs(i);
    }
    int color = 0;
    while(!s.empty()){
        int u = s.top(); s.pop();
        if(scc[u] == -1){
            scc[u] = ++color;
            dfs2(u,color);
        }
    }

    for (int i = 0; i < 1000010; ++i)
        if(scc[i] == scc[no(i)]) {
            cout << "NO\n";
            exit(0);
        }

    cout << "YES\n";
}

void add(int p, int q){
    G[no(p)].push_back(q);
    GT[q].push_back(no(p));
    G[no(q)].push_back(p);
    GT[p].push_back(no(q)); 
}
/*
   (p ^ ~q) v (~p ^ q)
   (p v ~p) ^ (p v q) ^ (~q v ~p) ^ (~q v q)
   */

int v[200010];
vector<int>doors[200010];

int main() {

    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0, u; i < m; i++) {
        cin >> u;

        while (u--) {
            int vv; cin >> vv;
            vv--;
            doors[vv].push_back(i);
        }

    }
    for (int i = 0; i < n; i++) {
        int p = doors[i][0];
        int q = doors[i][1];
        if (!v[i]) {
            add(no(p), q);
            add(p, no(q));
        } else {
            add(p, q);
            add(no(p), q);
        }
    }

    kosaraju();
    return 0;
}


