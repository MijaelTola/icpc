#include <bits/stdc++.h>

using namespace std;

int n,m;

char c[35][35];
long long dp[35][35][35][35];

bool fill1(int x, int y) {
    for (int i = x; i >= 0; i--) {
        for (int j = y; j >= 0; j--) {
            if(c[i][j] == 'R') return 0;
            c[i][j] = 'B';
        }
    }
    return 1;
}

bool fill2(int x, int y) {
    for (int i = x; i < n; ++i) {
        for (int j = y; j < m; ++j) {
            if(c[i][j] == 'B') return 0;
            c[i][j] = 'R';
        }
    }
    return 1;
  
}

long long f(int x, int y, int w, int z) {
    if(x > w) return 0;
    while(c[x][y] == '.' and c[x][y - 1] == '.' and y >= 0) y--;
    if(dp[x][y][w][z] != -1) return dp[x][y][w][z];
    long long ans = 0;
    for (int i = y; i <= z; ++i) {
        if(c[x][i] == '.') {
            ans += f(x + 1, y,w,i) + 1;
            if(c[x][i - 1] == 'B' and c[x + 1][i] == '.') {
                int dx = x;
                bool flag = 0;
                while(c[dx][i - 1] == 'B') flag = 1,dx++;
                dx -= flag;
                ans += f(dx + 1, y,w,i - 1);
            }
        }else break;
    }
    return dp[x][y][w][z] = ans;
}

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int dfs(int x, int y) {
    if(c[x][y] != '.') return 0;
    c[x][y] = 'z';
    for (int i = 0; i < 4; ++i) {
        int u = x + dx[i];
        int v = y + dy[i];
        if(u >= 0 and  u < n and v >= 0 and v < m) 
            dfs(u,v);
    }
}

void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) 
            cout << c[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char x; 
            cin >> x;
            c[i][j] = x;
        }
    }
    bool flag = 1;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            if(c[i][j] == 'B') flag &= fill1(i,j);
            if(c[i][j] == 'R') flag &= fill2(i,j);
        }
    if(!flag) return cout << "0\n",0;
    long long ans = 1;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            if(c[i][j] == '.') {
                long long cur = (f(i,j, n - 1, m - 1) + 1); 
                ans *= cur;
                dfs(i,j);
            }
        }
    cout << ans << "\n";
    return 0;
}
