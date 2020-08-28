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

vector<int> G[1010];
int vis[1010];
int n,m;
bool dfs(int u){
    vis[u] = 1;
    bool flag = false;
    for (int v:G[u]){
        if(!vis[v]) flag |= dfs(v);
        if(vis[v] == 1) return true;
    }
    vis[u] = 2;
    return flag;
}
int main(){

    memset(vis,0,sizeof vis);
    cin >>n >> m;
    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y);
    }

    bool ans = false;

    for (int i = 1; i <= n; ++i)
        if(!vis[i])
            ans |= dfs(i);

    cout << ans << "\n";
    return 0;
}

