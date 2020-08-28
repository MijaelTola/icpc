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
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<pair<int,int> > G[110];
int distances[110][110];
int q[5000][2];
void dijkstra(int pos, int x){
    priority_queue<pair<int,int> > q;
    q.push({-0,x});
    distances[pos][x] = 0;
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        for (pair<int,int> i: G[u]){
            int v = i.first;
            int wt = i.second;
            if(distances[pos][u]+wt < distances[pos][v]){
                distances[pos][v] = distances[pos][u]+wt;
                q.push({-distances[pos][v],v});
            }
        }
    }
}

void clear(){
    for (int i = 0; i < 110; ++i){
        G[i].clear();
        for (int j = 0; j < 110; ++j)
            distances[i][j] = INT_MAX;
    }
}

int k;
int dp[110][110][4];

int f(int pos,int curpos, int curload){
    if(pos == k) return 0;
    if(dp[pos][curpos][curload] != -1) return dp[pos][curpos][curload];
    int ans = 1e9; 
    int s = q[pos][0];
    int e = q[pos][1];
    int s1 = q[pos+1][0];
    if(curload == 2) ans = min(ans,f(pos+1,e,curload-1)+distances[curpos][e]);
    else if(curload > 0){
        if(pos+1 < k)ans = min(ans,f(pos,s1,curload+1)+distances[curpos][s1]);
        ans = min(ans,f(pos+1,e,curload-1)+distances[curpos][e]);
    }else ans = min(ans,f(pos,s,curload+1)+distances[curpos][s]);
    return dp[pos][curpos][curload] = ans;
}
int main(){
    
    ios::sync_with_stdio(false); cin.tie(0);
    int t; 
    cin >> t;
    for (int cs = 1; cs <= t; ++cs){
        int n,m;
        clear();
        memset(dp,-1,sizeof dp);
        cin >> n >> m >> k;
        for (int i = 0; i < m; ++i){
            int x,y,w;
            cin >> x >>y >> w;
            G[x].push_back({y,w});
            G[y].push_back({x,w});
        }
        for(int i = 1; i <= n; ++i) dijkstra(i,i);
        bool flag = true;
        for (int i = 0; i < k; ++i){
            cin >> q[i][0] >> q[i][1];
            if(distances[q[i][0]][q[i][1]] == INT_MAX) flag = false;
        }
        if(flag)cout << "Case #" << cs << ": " << f(0,1,0) << "\n";
        else cout << "Case #" << cs << ": " << -1 << "\n";
        
    }
    return 0;
}

