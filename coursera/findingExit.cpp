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
queue<int> q;
int main(){
    
    int n,m; cin >> n >> m;
    int u,v;

    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cin >> u >> v;
    bool flag = false;
    memset(vis,false,sizeof vis);
    q.push(u);
    while(!q.empty()){
        int x; x = q.front(); q.pop();
        if(x == v){flag = true; break;}
        for (int y: G[x])
            if(!vis[y]){vis[y] = true; q.push(y);}
    }
    if(flag) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}

