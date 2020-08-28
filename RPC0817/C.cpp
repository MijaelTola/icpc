#include <bits/stdc++.h>

using namespace std;

vector<int> G[200010];
int trad[200010];
int curT[200010];
bool leave[200010];

void dfs(int u){
    leave[u] = 1;
    for (int i = 0; i < (int)G[u].size(); ++i){
        int v = G[u][i];
        curT[v]++;
        if(curT[v] >= (trad[v] + 1)/2 and !leave[v]) dfs(v);
    }
}

int main(){
    memset(leave,false,sizeof leave);
    int c,p,l,x;
    cin >> c >> p >> x >> l;
    for (int i = 0; i < p; ++i){
        int dx,dy; cin >> dx >> dy;
        G[dx].push_back(dy);
        G[dy].push_back(dx);
        trad[dx]++;
        trad[dy]++;
    }

    dfs(l);
    if(leave[x]) cout << "leave\n";
    else cout << "stay\n";
    return 0;
}

