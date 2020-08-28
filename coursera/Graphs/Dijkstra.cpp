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

vector<pair<int,int> > G[1010];
int d[1010];

int main(){
    for(int i = 0; i < 1010; ++i) d[i] = 1e8;
    int n,m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int x,y,w; cin >> x >>y >> w;
        G[x].push_back({y,w});
    }
    int x,y; cin >> x >> y;
    priority_queue<int> q;
    q.push(x);
    d[x] = 0;
    while(!q.empty()){
        int u = q.top(); q.pop();
        for (pair<int,int>v: G[u]){
            if(d[u]+v.second < d[v.first]){
                d[v.first] = d[u] + v.second;
                q.push(v.first);
            }
        }
    }
    if(d[y] == 1e8) cout << -1 << endl;
    else cout << d[y] << endl;
    return 0;
}

