#include <bits/stdc++.h>

using namespace std;

int n,m;
int s[51];
vector<int> G[51],G2[111];
int path[51][51];
int parent[51];
int marked[111];

void floydWarshall() {
    for (int k = 1; k <= n; ++k) 
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if(path[i][k] + path[k][j] < path[i][j])
                    path[i][j] = path[i][k] + path[k][j];

}

void f(int u, int pt = -1) {
    parent[u] = pt;
    for (auto v: G[u]) {
        if(pt == v) continue;
        f(v,u);
    }
}

bool dfs(int u) {
    if(parent[u]) return 0;
    parent[u] = 1;
    for (int v: G2[u])
        if(marked[v] == -1 or dfs(marked[v])) {
            marked[v] = u;
            marked[u] = v;
            return 1;
        }
    return 0;
}

int mbm() {
    memset(marked, -1, sizeof marked);
    memset(parent, 0, sizeof parent);
    for (int i = 1; i <= n; ++i)
        if(marked[i] == -1 and s[i]) {
            memset(parent, 0,sizeof parent);
            dfs(i);
        }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if(marked[i] != -1) ans++;
    return ans;
}

int main() {
    
    for (int i = 0; i < 51; ++i)
        for (int j = 0; j < 51; ++j)
            path[i][j] = 1e9;

    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int x,y,w;
        cin >> x >> y >> w;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
        path[x][y] = w;
        path[y][x] = w;
    }
    for (int i = 1; i <= n; ++i)
        path[i][i] = 0;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        s[x] = 1;
    }
    
    floydWarshall();

    auto ver = [] (int d) {
        
        for (int i = 1; i <= n; ++i) {
            f(i); 
            memset(marked, 0, sizeof marked);
            for (int j = 1; j <= n; ++j) {
                if(!s[j]) continue;
                int u = j;
                while(u != -1) {
                    if(path[j][u] >= d or path[j][parent[u]] > d) marked[u] = 1;
                    u = parent[u];
                }
            }
            for (int j = 1; j <= n; ++j)
                G2[j].clear();
            int cnt = 0;
            for (int j = 1; j <= n; ++j) {
                cnt += marked[j];
                if(!s[j]) continue;
                for (int k = 1; k <= n; ++k) {
                    if(marked[k] and path[j][k] <= d) {
                        G2[j].push_back(k + n);
                        G2[k + n].push_back(j);
                    }
                }
            }

            if(mbm() == cnt) 
                return 1;
            
        }

        return 0;
    };

    int a = -1, b = 1e9;
    
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) b = mid;
        else a = mid;
    }
    cout << b << "\n";

    return 0;
}

