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
int vis[100010];
int main(){
    memset(vis,-1,sizeof vis);
    int n,m; cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int u,s; cin >> u >> s;
    queue<int> q;
    q.push(u);
    vis[u] = 0;
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(x == s) break;
        for (int v: G[x]){
            if(vis[v] == -1){
                vis[v] = vis[x]+1;
                q.push(v);
            }
        }
    }
    cout << vis[s] << endl;
    return 0;
}

