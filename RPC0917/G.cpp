#include <bits/stdc++.h>

using namespace std;

map<string,int> mp;
string s[500010];
vector<int> G[500010];
bool vis[500010];
int ld[500010][2];
vector<pair<pair<int,int>, string > > ans;
stack<int> ss;
void dfs(int u){
    for (int i = 0; i < (int)G[u].size(); ++i){
        int v = G[u][i];
        if(!vis[v]){
            vis[v] = 1;
            dfs(v);
        }
    }
    ss.push(u);
}
void solve(int u){
    memset(vis,false,sizeof vis);
    vis[u] = 1;
    dfs(u);
    ld[u][0] = 1;
    while(!ss.empty()){
        int v = ss.top();
        ss.pop(); 
        if(vis[v] != -1){
            for (int i = 0; i < (int)G[v].size(); ++i){
                int x = G[v][i];
                if(ld[x][0] < ld[v][0] + 1)
                    ld[x][0] = ld[v][0] + 1;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    while(cin >> n){
        for (int i = 0; i < 500010; ++i){
            G[i].clear();
            ld[i][0] = -1;
            ld[i][1] = 0;
        }
        ans.clear();
        mp.clear();
        int c = 0;
        for (int i = 0; i < n; ++i){
            string x,y; cin >> x  >> y;
            if(!mp.count(x)){
                mp[x] = ++c;
                s[c] = x;
            }
            if(!mp.count(y)){
                mp[y] = ++c;
                s[c] = y;
            }
            int dx = mp[x];
            int dy = mp[y];
            G[dx].push_back(dy);
            ld[dy][1]++;
        }
        int id = -1;
        for (int i = 1; i <= c; ++i){
            if(!ld[i][1]){
                id = i;
                solve(id);
            }
        }
        
        
        for (int i = 1; i <= c; ++i)
            ans.push_back(make_pair(make_pair(ld[i][0],ld[i][1]),s[i]));
        
        sort(ans.begin(),ans.end());
        for (int i = 0; i < (int)ans.size(); ++i)
            cout << ans[i].first.first << "." << ans[i].first.second << " " << ans[i].second << "\n";

    }
    return 0;
}

