#include <bits/stdc++.h>

using namespace std;

int n,k;
int dx[] = {0,1};
int dy[] = {1,0};
char c[2010][2010];
int d[2010][2010];
int dis[2010][2010];

int main() {

    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
            d[i][j] = 1e9;
        }

    queue<pair<int,int> > q;

    priority_queue<pair<int, pair<int,int> > > Q;
    Q.push({0,{0,0}});
    d[0][0] = (c[0][0] != 'a');
    dis[0][0] = 1;
    while(!Q.empty()) {
        int x = Q.top().second.first;
        int y = Q.top().second.second;
        Q.pop();

        for (int i = 0; i < 2; ++i) { 
            int u = dx[i] + x;
            int v = dy[i] + y;

            if(u < n and v < n and d[x][y] + (c[u][v] != 'a') < d[u][v]) {
                d[u][v] = d[x][y] + (c[u][v] != 'a');
                dis[u][v] = dis[x][y] + 1;
                Q.push({-dis[u][v], {u,v}});
            }
        }
    }


    
    int a = 1e9;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(d[i][j] <= k) {
                if(dis[i][j] > cur) {
                    a = dis[i][j];
                    cur = dis[i][j];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(dis[i][j] == a and d[i][j] <= k) {
                q.push({i,j});
            }
        }
    }
    if(a == 1e9) a = 0;
    //cout << a << "\n";
    string ans = "";
    for (int i = 0; i < a; ++i)
        ans += "a";

    queue<pair<int,int> > q2;
    if(q.empty()) {
        q.push({0, 0});
        ans += c[0][0];
    }

    while(!q.empty()) {
        char mn = 'z';
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 2; ++i) {
                int u = dx[i] + x;
                int v = dy[i] + y;
                if(u < n and v < n) {
                    mn = min(mn, c[u][v]);
                    q2.push({u,v});
                }
            }
        }
        ans += mn;

        while(!q2.empty()) {
            int x = q2.front().first;
            int y = q2.front().second;
            q2.pop();
            if(c[x][y] == mn) q.push({x,y});
        }
    }

    ans.pop_back();
    cout << ans << "\n";
    return 0;
}

