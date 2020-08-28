#include <bits/stdc++.h>

using namespace std;

int n,m;
char c[1010][1010];
int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {1,1,0,-1,-1,-1,0,1};
int sc[1010][1010];
int color[1000010];
bool vis[1000010];
bool ver(int u,int v){
    return u >= 0 and u <= n + 1 and v >= 0 and v <= m + 1 and c[u][v] != '*';
}
void dfs(int x, int y, int num){
    for (int i = 0; i < 8; ++i){
        int u = x + dx[i];
        int v = y + dy[i];
        if(ver(u,v) and sc[u][v] == -1){
            sc[u][v] = num;
            if(c[u][v] == '#') color[num]++; 
            dfs(u,v,num);
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m){
        memset(c,'.', sizeof c);
        memset(color,0,sizeof color);
        memset(vis,false,sizeof vis);
        memset(sc, -1, sizeof sc);
        
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> c[i][j];
        int col = 0;
        for (int i = 0; i <= n + 1; ++i)
            for (int j = 0; j <= m + 1; ++j)
                if(sc[i][j] == -1 and c[i][j] != '*') {
                    sc[i][j] = ++col;
                    if(c[i][j] == '#') color[col]++;
                    dfs(i,j,col);
                }

        int ans = color[1];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j){
                bool flag = 0;
                int cur = 0;
                if(c[i][j] == '*'){
                    for (int k = 0; k < 8; ++k){
                        int u = dx[k] + i;
                        int v = dy[k] + j;
                        if(ver(u,v)){
                            int col = sc[u][v];
                            if(vis[col]) continue;
                            vis[col] = 1;
                            cur += color[col];
                            if(col == 1) flag = 1;
                        }
                    }
                    if(flag) ans = max(ans,cur);
                    for (int k = 0; k < 8; ++k){
                        int u = dx[k] + i;
                        int v = dy[k] + j;
                        if(ver(u,v)){
                            int col = sc[u][v];
                            vis[col] = 0;
                        }
                    }
                }
            }
        cout << ans << "\n";
    }
    return 0;
}

