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
const double MAXN = 1e25;
const double ma = MAXN-1.0;
vector<pair<int,double> > G[1010];
double dis[1010];
int path[1010];
bool vis[1010];
int main(){
    memset(path,-1,sizeof path);
    memset(vis,false,sizeof vis);
    int n,m; cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int x,y;
        ll w; cin >> x >> y >> w;
        G[x].push_back({y,w});
    }
    for (int i = 0; i < 1010; ++i) dis[i] = MAXN;
    int x; cin >> x;
    dis[x] = 0LL;
    for (int i = 1; i <= n-1; ++i)
        for (int u =1; u <= n; ++u)
            if(dis[x] != MAXN)
                for (pair<int,ll>v: G[u])
                    dis[v.first] = min(dis[v.first],dis[u] + v.second);

    queue<int> q;
    for (int u = 1; u <= n; ++u)
        if(dis[u] != MAXN)
            for (pair<int,ll> v: G[u])
                if(dis[v.first] > dis[u]+v.second){
                    q.push(v.first);
                    q.push(u);
                }
 
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (pair<int,ll> v: G[u]){
            if(!vis[v.first]){
                vis[v.first] = true;
                q.push(v.first);
            }
        }
    }

    for (int i = 1; i <= n; ++i){
        if(dis[i] == MAXN)  cout << "*";
        else if(vis[i]) cout << "-";
        else cout << dis[i];
        cout << "\n";
    }
    return 0;
}

