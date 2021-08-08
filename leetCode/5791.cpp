#include <bits/stdc++.h>

using namespace std;

int vis[510][510];
vector<vector<int>>A, B;
int a = 0, b = 0;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
void dfs(int x, int y) {
    if(vis[x][y]) return;
    cout << x << " " << y << "\n"
    vis[x][y] = 1;
    a += A[x][y] == '1';
    b += B[y][y] == '1';

    for (int i = 0; i < 4; ++i) {
        int u = dx[i] + x;
        int v = dy[i] + y;
        if(u >= 0 and v >= 0 
                and u < (int)B.size() 
                and v < (int)B[i].size()
                and B[x][y] == '1'
                ) {
            dfs(u, v);
        }
    }
}
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    A = grid1;
    B = grid2;
    memset(vis, 0, sizeof vis);

    int ans = 0;
    for (int i = 0; i < (int)B.size(); ++i) {
        for (int j = 0; j < (int)B[i].size(); ++j) {
            if(!vis[i][j] and B[i][j] == '1') {
                a = 0, b = 0;
                dfs(i,j);
                    cout << i << " " << j << ": " << a << " - " << b << endl;
                if(a == b) ans++;
            }
        }
    }
    return ans;
}


int main() {

    return 0;
}

