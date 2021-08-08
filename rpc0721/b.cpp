#include <bits/stdc++.h>

using namespace std;

int n,m,k;
char c[11][11];
int vis[11][11][110][110][10][2];
string s;

int dx[] = {1,-1,0,0,1,-1,1,-1};
int dy[] = {0,0,-1,1,1,-1,-1,1};

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) 
            cin >> c[i][j];

    cin >> k >> s;

    queue<tuple<int,int,int,int,int, int> > q;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) 
            if(c[i][j] == s[0]) {
                q.push({i, j, 1, 0, 9, 1});
            }

    while(!q.empty()) {
        auto tp = q.front();
        q.pop();
        int x = get<0> (tp);
        int y = get<1> (tp);
        int pos = get<2> (tp);
        int cur = get<3> (tp);
        int dir = get<4> (tp);
        int first = get<5> (tp);

        if(pos == (int)s.size() and cur == k) {
            return cout << "Yes\n", 0;
        }
        if(vis[x][y][pos][cur][dir][first]) continue;
        vis[x][y][pos][cur][dir][first] = 1;

        for (int i = 0; i < 8; ++i) {
            int u = dx[i] + x;
            int v = dy[i] + y;

            if(u >= 0 and u < n and v >= 0 and v < m and s[pos] == c[u][v]) {
                if(i != dir) {
                    if(first) {
                        q.push({u, v, pos + 1, cur, i, 0 });
                    } else if(cur + 1 <= k) {
                        q.push({u, v, pos + 1, cur + 1, i, 0 });
                    }
                } else {
                    q.push({u, v, pos + 1, cur, i, 0});
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}

