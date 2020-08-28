#include <bits/stdc++.h>

using namespace std;

int c[3][3];
int dc[3][3];
int mask;

int dx[] = {1,-1,0,0,1,1,-1,-1};
int dy[] = {0,0,-1,1,1,-1,-1,1};

bool ver(int x, int y) {
    return x >= 0 and x < 3 and y >= 0 and y < 3;
}
bool dfs(int x,int y, int cur) {
    if(cur == 10) return 1;
    bool ans = 0;
    for (int i = 0; i < 8; ++i) {
        int u = dx[i] + x;
        int v = dy[i] + y;
        if(ver(u,v)) {
            if(dc[u][v] == cur) {
                ans |= dfs(u, v, cur + 1);
            }
        }
    }
    return ans;
}
int main() {
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            char x;
            cin >> x;
            c[i][j] = (x - '0');
            mask |= (1 << c[i][j]);
        }
    }

    vector<int> v;

    for (int i = 1; i <= 9; ++i)
        if(!(mask & (1 << i)))
            v.push_back(i);

    int ans = 0;
    do {

        int p = 0;
        int x = -1,y = -1;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j) {
                if(c[i][j] != 0) dc[i][j] = c[i][j];
                else dc[i][j] = v[p++];
                if(dc[i][j] == 1) x = i, y = j;
            }

        if(dfs(x,y,2)) 
            ans++;
        
    } while(next_permutation(v.begin(), v.end()));
    cout << ans << "\n";
    return 0;
}

