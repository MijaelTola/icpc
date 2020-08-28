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

using namespace std;

typedef long long ll;
vector<int> G[510];
int val[510];
int n;
int bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,val[x]});
    vector<bool> vis(510,false);
    vis[x] = true;
    while(!q.empty()){
        int u = q.front().first;
        int g = q.front().second;
        q.pop();
        if(u == y) return g;
        for(int i: G[u]){

            if(!vis[i]){
                vis[i] = true;
               // cout << u << " " << i << " " << val[u] << " " << val[i] <<endl;
                q.push({i,__gcd(val[i],g)});
            }
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> n){
        for (int i = 0; i < 510; ++i){
            G[i].clear();
            val[i]= 0;
         }
        for (int i = 0; i < n; ++i) cin >>val[i];
        for(int i = 0; i< n-1; ++i){
            int x,y; cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int q; cin >> q;
        while(q--){
            int c,x,y;
            cin >> c >> x >> y;
            if(c == 1) cout << bfs(x,y) << "\n";
            else val[x] = y;
        }
    }
    return 0;
}

