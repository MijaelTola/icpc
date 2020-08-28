#include <bits/stdc++.h>

using namespace std;

int n,m,k;

int G[1010][1010];
int d[1010][1010];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool ver(int h) {
    
    queue<pair<pair<int,int>, int> > q;

    for (int i = 0; i < m; ++i) {
        q.push({{0,i}, G[0][i] < h});
    }

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int c = q.front().second;
        q.pop();
        cout << x << " " << y  << " " << c << "lol\n";
        if(x == n - 1) return 1;
        for (int i = 0; i < 4; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if(u >= 0 and u < n and v >= 0 and v < m) {
                if(G[u][v] < h and d[u][v] > c + 1 and c + 1< k) {
                    d[u][v] = c + 1;
                    q.push({{u,v}, c + 1});
                } else if(d[u][v] > c)q.push({{u,v}, c});
            }
        }
    }

    return 0;
}
int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            cin >> G[i][j];
            d[i][j] = 1e9;
        }

    cout << ver(3) << "gg\n";
    /*
    int a = 0, b = 1e9;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) a = mid;
        else b = mid;
    }
    cout << a << "\n"; */
    return 0;
}

