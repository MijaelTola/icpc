#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

bool vis[30][30];
int cur[30][30];
int n,m;
int f(int x, int y, int pos){
    int ans = 1;
    cout << x << " " << y <<"\n";
    bool flag = false;
    for (int i = pos; i < pos + 4; ++i){
        int p = i % 4;
        int u = x + dx[p];
        int v = y + dy[p];
        if(u >= 0 and u < n and y >= 0 and y < m and !vis[u][v]){
            flag = true;
            vis[u][v] = true;
            ans += f(u,v,p);
        }
    }
    if(!flag){
        int u = x + dx[(pos + 1) % 4]; 
        int v = y + dy[(pos + 1) % 4];
        return cur[x][y] = cur[u][v];
    }
    return cur[30][30] = ans;
}

int main(){
    memset(vis,false,sizeof vis);
    cin >> n >> m;
    cout << f(n - 1,0,0) << "\n";
 /*   for (int i = 2; i <= 25; ++i)
        for (int j = 1; j <= 25; ++j)
            m[i][j] = f(i,j);*/
    return 0;
}

