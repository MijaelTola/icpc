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
int color[100010];
int main(){
    memset(color,-1,sizeof color);
    int n,m; cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y); 
        G[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    bool bipartite = true;
    while(!q.empty() and bipartite){
        int u = q.front(); q.pop();
        for (int v: G[u]){
            if(color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }else if(color[v] == color[u]){
                bipartite = false; break;
            }
        }
    }

    cout << bipartite << endl;
    return 0;
}

