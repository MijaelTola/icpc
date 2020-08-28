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

using namespace std;

typedef long long ll;

char c[110][110][110];
int d[110][110][110];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

struct pos{
    int x,y,z;
    pos(){}
    pos(int zz, int xx, int yy){  x = xx; y = yy; z = zz;   }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,p;
    int sx,sy,sz;
    while(cin >> n >> m >> p and n and m and p){
        queue<pos> q;
        memset(d,-1,sizeof d);
        for (int i = 0; i < p; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < m; ++k){
                    cin >> c[i][j][k];
                     if(c[i][j][k] == 'S'){
                         sz = i;
                         sx = j;
                         sy = k;
                     }
                }
        bool flag = false;
        d[sz][sx][sy] = 0;
        q.push(pos(sz,sx,sy));
        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            int z = q.front().z;
            q.pop();
            if(c[z][x][y] == 'E'){
                cout << d[z][x][y] << "\n";
                flag = true;
                break;
            }
            for (int i = 0; i < 4; ++i){
                int u = x + dx[i];
                int v = y + dy[i];
                if(u >= 0 and u < n and v >= 0 and v < m and d[z][u][v] == -1 and c[z][u][v] != '#'){
                    d[z][u][v] = d[z][x][y] + 1;
                    q.push(pos(z,u,v));
                }
            }
            if(c[z][x][y] == '-'){
                int dz = z+1; 
                int bz = z-1;
                if(dz >= 0 and dz < p and d[dz][x][y] == -1 and c[dz][x][y] == '-'){
                    d[dz][x][y] = d[z][x][y]+1;
                    q.push(pos(dz,x,y));
                }
                if(bz >= 0 and bz < p and d[bz][x][y] == -1 and c[bz][x][y] == '-'){
                    d[bz][x][y] = d[z][x][y] +1;
                    q.push(pos(bz,x,y));
                }
            }
        }
        if(!flag) cout << -1 << "\n";
    }
    return 0;
}

