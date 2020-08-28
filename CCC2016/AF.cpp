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

typedef long long ll;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
char c[1010][1010];
int d[1010][1010];
int n,m;
int color;
void dfs(int x,int y){
    for(int i = 0; i < 4; ++i){
        int u = x + dx[i];
        int v = y + dy[i];
        if(u >= 0 and u < n and v >= 0 and v < m and c[u][v] == '#' and d[u][v] == 0){
            d[u][v] = d[x][y];
            dfs(u,v);
        }
    }
}

int bfs(int i,int j){
    queue<pair<int,int> > q;
    q.push({i,j});
    int col;
    bool flag = false;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i){
            int u = dx[i] + x;
            int v = dy[i] + y;
            if(u >= 0 and u < n and v >= 0 and v < m){
                if(c[u][v] == '#' and !flag) col = d[u][v];
                if(d[u][v] == 0){
                    d[u][v] = -2;
                    q.push({u,v});
                }
            }else{
                col = 0;
                flag = true;
            }
        }
    }
    return col;
}
int ans[1111];
int main(){
    memset(d,0,sizeof d);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin>>c[i][j];
    
    color = 0;
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if(c[i][j] == '#' and d[i][j] == 0){
                d[i][j] = ++color;
                dfs(i,j);
            }
        }
    }
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if(c[i][j] == '.' and d[i][j] == 0){ 
                int a = bfs(i,j);
                ans[a]++;  
            }
        }
    }
    sort(ans+1,ans+color+1);
    cout << color << endl;
    for (int i = 1; i <= color; ++i)
        cout << ans[i] << " ";
    return 0;
}

