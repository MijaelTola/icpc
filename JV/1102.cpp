#include <bits/stdc++.h>

using namespace std;

int c[55][55];

int dx[] = {1,-1,1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0,1,-1};
int main(){
    memset(c, -1, sizeof c);
    int n,m,a;
    while(cin >> n >> m >> a and n and m and a){
        for (int i = 0; i < a; ++i){
            int x,y; cin >> y >> x;
            c[x][y] = 2;
            for (int j = 0; j < 8; ++j){
                int u = dx[j] + x;
                int v = dy[j] + y;
                if(c[u][v] == -1) c[u][v] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans += (c[i][j] == 1);
        cout << ans << "\n";
    }
    
    return 0;
}

