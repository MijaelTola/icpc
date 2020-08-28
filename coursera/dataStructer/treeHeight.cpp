#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> G[100010];
queue<pair<int,int> > q;
bool vis[100010];
int main(){
    memset(vis,false,sizeof vis);
    int n; cin >> n;
    int root;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        if(x == -1) root = i;
        else{
            G[i].push_back(x);
            G[x].push_back(i);
        }
    }
    q.push({root,1});

    int ans = 0;

    while(!q.empty()){
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        if(vis[u]) continue;
        ans = max(ans,v);
        vis[u] = true;
        for(int i: G[u]){
            if(!vis[i]) q.push({i,v+1});
        }
    }
    cout << ans << endl;
    return 0;
}
