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
bool vis[1010];

void dfs(int u){
    for (int v: G[u]){
        if(!vis[v]){
            vis[v] = true;
            dfs(v);
        }
    }
}
int main(){
    memset(vis,false,sizeof vis);
    int n,m; cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i)
        if(!vis[i]){vis[i] = true; ans++; dfs(i);}
    cout << ans << endl;
    return 0;
}

