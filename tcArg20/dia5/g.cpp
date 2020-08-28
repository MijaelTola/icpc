#include <bits/stdc++.h>

using namespace std;

int p[100010];
void init() {for (int i = 0; i < 100010; ++i) p[i] = i;}
int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
void merge(int x,int y) { p[find(y)] = find(x);}

int is[100010];
vector<tuple<int,int,int> > e;
vector<pair<int,int> > G[100010];
int ans = 0;

bool dfs(int u, int pt = -1) {
    
    int can = is[u];
    for (auto p: G[u]) {
        int v = p.first;
        if(v == pt) continue;
        bool c = dfs(v, u);
        can |= c;
        if(c) ans = max(ans, p.second);
    }

    return can;
}
int main() {

    int n,m,k;
    cin >> n >> m >> k;
    
    int id = -1;
    vector<int> s;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        is[x] = 1;
        id = x;
        s.push_back(x);
    }

    for (int i = 0; i < m; ++i) {
        int x,y,w;
        cin >> x >> y >> w;
        e.push_back({w,x,y});
    }

    sort(e.begin(), e.end());

    init();
    for (auto t: e) {
        int x,y,w;
        tie(w, x, y) = t;
        if(find(x) != find(y)) {
            merge(x,y);
            G[x].push_back({y,w});
            G[y].push_back({x,w});
        }
    }


    dfs(id);

 
    for (int i = 0; i < k; ++i)
        cout << ans << " ";
    cout << "\n";

    return 0;
}

