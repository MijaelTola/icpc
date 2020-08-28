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

vector<int> G[100010];
vector<int> ans;
bool vis[100010];
void dfs(int u){
    for (int v: G[u]){
        if(!vis[v]){vis[v] = true;dfs(v);}
    }
    ans.push_back(u);
}
int main(){
    memset(vis,false,sizeof vis);
    int n,m; cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i){
        if(!vis[i]){
            vis[i] = true;
            dfs(i);
        }
    }
    reverse(ans.begin(),ans.end());
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}

