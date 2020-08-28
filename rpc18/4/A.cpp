#include <bits/stdc++.h>

using namespace std;

int n,m,q;
stack<pair<pair<int,int>,pair<int,int> > > s;
vector<int> ans;
int parent[1000100];

int c[1010][1010];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void init() {
    for (int i = 0; i < 1000100; ++i) {
        parent[i] = i;
    }
}


int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x,int y) {
    int px = find(x);
    int py = find(y);
    parent[py] = px;
}

void dfs(int x, int y, int col) {
    c[x][y] = -col;
    for (int i = 0; i < 4; ++i) {
        int u = dx[i] + x;
        int v = dy[i] + y;
        if(u >= 0 and u < n and v >= 0 and v < m and c[u][v] == 0) {
            dfs(u,v,col);
        }
    }
}

void print() {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(c[i][j] >= 0) cout << "# ";
            else cout << find(-c[i][j]) << " ";
        }
        cout << "\n";
    }

}
int main(){
    memset(c,0,sizeof c);
    cin >> n >> m >> q;
    init();
    while(q--) {
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        x--,y--,a--,b--;
        s.push({{x,y},{a,b}});
        if(x == a) {
            for (int i = min(y,b); i <= max(y,b); ++i) {
                c[x][i]++;
            }
        } else {
            for (int i = min(x,a); i <= max(x,a); ++i) {
                c[i][y]++;
            }
        }
    }

    int color = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(c[i][j] == 0) {
                dfs(i,j, ++color);
            }
        }
    }
    ans.push_back(color);
    int as = color;
    while(!s.empty()) {
        int x = s.top().first.first;
        int y = s.top().first.second;
        int a = s.top().second.first;
        int b = s.top().second.second;
        s.pop();
        if(x == a) {
            for (int i = min(y,b); i <= max(y,b); ++i) 
                c[x][i]--;
            
            for (int i = min(y,b); i <= max(y,b); ++i) {
                if(c[x][i] != 0) continue;
                color++;
                c[x][i] = -color;
                bool first = 1;
                as++;
                for (int j = 0; j < 4; ++j) {
                    int u = dx[j] + x;
                    int v = dy[j] + i;
                    if(u >= 0 and u < n and v >= 0 and v < m 
                            and c[u][v] < 0) {
                        int p = abs(c[u][v]);
                        if(find(p) != find(color)) {
                            as--;
                            Union(p,color);
                        }
                    }
                }
            }
        } else {
            for (int i = min(x,a); i <= max(x,a); ++i) 
                c[i][y]--;
            for (int i = min(x,a); i <= max(x,a); ++i) {
                if(c[i][y] != 0) continue;
                color++;
                c[i][y] = -color;
                bool first = 1;
                as++;
                for (int j = 0; j < 4; ++j) {
                    int u = dx[j] + i;
                    int v = dy[j] + y;
                    if(u >= 0 and u < n and v >= 0 and v < m 
                            and c[u][v] < 0) {
                        int p = abs(c[u][v]);
                        if(find(p) != find(color)) {
                            as--;
                            Union(p,color);
                        }
                    }
                }
            }
        }
        ans.push_back(as);

    }
    for (int i = ans.size() - 2; i >= 0; --i)
        cout << ans[i] << "\n";

  
    return 0;
}


