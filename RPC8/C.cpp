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

int tm[1000100];

struct guys{
    bool god;
    int x,y;
    guys(int xx,int yy,bool g){
        x = xx; y = yy;
        god = g;
    }
};
char c[1010][1010];
bool vis[1010][1010];
int dx[] = { 0, 1, 0, -1};
int dy[] = { 1, 0, -1, 0};
int main(){
    
    int t; cin >> t;

    while(t--){
        queue<guys> q;
        int n,m; cin >> n >> m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j){
                cin >> c[i][j];
                if(c[i][j] == 'R') q.push({i,j,true});
                if(c[i][j] == 'M') q.push({i,j,false});
            }

        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            bool g = q.front().god;
            q.pop();
            if(g){
                bool flag = 0;
                for (int i = 0; i < 4; ++i){
                    int u = x + dx[i];
                    int v = y + dx[i];
                    if(!vis[u][v] and c[u][v] == 'R'){
                        flag = true;
                        q.push(guys(u,v,true));
                        break;
                    }
                }
                if(flag) continue;
                for (int i = 0; i < 4; ++i){
                    int u = x + dx[i];
                    int v = y + dy[i];
                    if(!vis[u][v]) q.push(guys(u,v,false));
                }
            }
            
        }
    }
    return 0;
}

