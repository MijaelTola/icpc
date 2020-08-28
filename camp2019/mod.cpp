#include <bits/stdc++.h>

using namespace std;

struct node {
    long long l, d, D, L;
    pair<long long, int> lmx, lmx2, lmx3;
    pair<long long, int> dmx, dmx2, dmx3;
};

int n,du,dv,mdu,mdv, mx, mn;
node data[500010];
vector<int> G[500010];
int way[500010];
bool vis[500010];

void dfs(int ini) {
    memset(vis, 0, sizeof vis);
    stack<pair<int,int> > s;
    s.push({ini,ini});
    while(!s.empty()) {
        int u = s.top().first;
        int p = s.top().second;
        if(vis[u]) {
            s.pop();
            //calculating deepest node in subtree u
            for (int i = 0; i < (int) G[u].size(); ++i) {
                int v = G[u][i];
                if(v == p) continue;
                data[u].l = max(data[u].l, data[v].l + 1);
                if(data[v].l > data[u].lmx.first) {
                    data[u].lmx3 = data[u].lmx2;
                    data[u].lmx2 = data[u].lmx;
                    data[u].lmx = {data[v].l, i};
                } else if(data[v].l > data[u].lmx2.first) {
                    data[u].lmx3 = data[u].lmx2;
                    data[u].lmx2 = {data[v].l, i};
                } else if(data[v].l > data[u].lmx3.first) 
                    data[u].lmx3 = {data[v].l, i};

                if(data[v].d > data[u].dmx.first) {
                    data[u].dmx3 = data[u].dmx2;
                    data[u].dmx2 = data[u].dmx;
                    data[u].dmx = {data[v].d, i};
                } else if(data[v].d > data[u].dmx2.first) {
                    data[u].dmx3 = data[u].dmx2;
                    data[u].dmx2 = {data[v].d, i};
                } else if(data[v].d > data[u].dmx3.first) 
                    data[u].dmx3 = {data[v].d, i};
            }

            //calculating max diameter in subtree u
            //u is an endpoint of diameter in subtree u
            data[u].d = max(data[u].d, data[u].lmx.first + 1);
            //u is not part of diameter in subtree u
            data[u].d = max(data[u].d, data[u].dmx.first);
            //diameter pass throught u
            if(u == 1 and G[u].size() >= 2) //if u root 
                data[u].d = max(data[u].d, data[u].lmx.first + data[u].lmx2.first + 2); 
            else if(u != 1 and G[u].size() >= 3) //if u is not root 
                data[u].d = max(data[u].d, data[u].lmx.first + data[u].lmx2.first + 2); 
            continue;
        }
        vis[u] = 1;
        data[u].lmx.first = data[u].lmx2.first = data[u].lmx3.first = -1;
        for (int v: G[u]) {
            if(v == p) continue;
            s.push({v, u});
        }
    }
}

void dfs2(int ini) {
    memset(vis, 0,sizeof vis);
    stack<pair<int,int> > s;
    s.push({ini,ini});
    while(!s.empty()) {
        int u = s.top().first;
        int p = s.top().second;
        if(vis[u]) {
            s.pop();
            continue;
        }
        vis[u] = 1;
        for (int i = 0; i < (int) G[u].size(); ++i) {
            int v = G[u][i];
            if(v == p) continue;
            //calculating v's complement deep
            if(u != 1) data[v].L = data[u].L + 1;
            if(i != data[u].lmx.second) data[v].L = max(data[v].L, data[u].lmx.first + 1);
            else {
                if((u == 1 and G[u].size() >= 2) or 
                   (u != 1 and G[u].size() >= 3))
                    data[v].L = max(data[v].L, data[u].lmx2.first + 1);
            }

            //calculating v's diameter complement
            

            //u is not part of v's diameter complement
            
            data[v].D = 0;
            if(u != 1) 
                data[v].D = max(data[v].D, data[u].D);
            if(i != data[u].dmx.second) { 
                if((u == 1 and G[u].size()) or (u != 1 and G[u].size() >= 2))
                    data[v].D = max(data[v].D, data[u].dmx.first);
            } else if((u == 1 and G[u].size() >= 2) or (u != 1 and G[u].size() >= 3))
                data[v].D = max(data[v].D, data[u].dmx2.first);
            
            //u is an endpoint of v's diameter complement
            
            if(u != 1) data[v].D = max(data[v].D, data[u].L + 1);
            
            if(i != data[u].lmx.second) {
                if((u == 1 and G[u].size()) or (u != 1 and G[u].size() >= 2))
                    data[v].D = max(data[v].D, data[u].lmx.first + 1);
            } else if((u == 1 and G[u].size() >= 2) or (u != 1 and G[u].size() >= 3))
                data[v].D = max(data[v].D, data[u].lmx2.first + 1);

            //v's diameter pass throught u
            //child to parent
            
            if(i != data[u].lmx.second) {
                if(u != 1 and G[u].size() >= 2) 
                    data[v].D = max(data[v].D, data[u].lmx.first + data[u].L + 2);    
            } else {
                if(u != 1 and G[u].size() >= 3) 
                    data[v].D = max(data[v].D, data[u].lmx2.first + data[u].L + 2);
            }

            //child to child
            if(i == data[u].lmx.second) {
                if((u == 1 and G[u].size() >= 3) or (u != 1 and G[u].size() >= 4))
                    data[v].D = max(data[v].D, data[u].lmx2.first + data[u].lmx3.first + 2);
            } else if(i == data[u].lmx2.second) {
                if((u == 1 and G[u].size() >= 3) or (u != 1 and G[u].size() >= 4))
                    data[v].D = max(data[v].D, data[u].lmx.first + data[u].lmx3.first + 2);
            } else if(i == data[u].lmx3.second) {
                data[v].D = max(data[v].D, data[u].lmx.first + data[u].lmx2.first + 2);
            } else {
                if((u == 1 and G[u].size() >= 2) or (u != 1 and G[u].size() >= 3)) 
                    data[v].D = max(data[v].D, data[u].lmx.first + data[u].lmx2.first + 2);
            }
            
            s.push({v, u});
        }
    }
}

void dfs3(int ini) {
    memset(vis, 0, sizeof vis);
    stack<pair<int,int> > s;
    s.push({ini, ini});
    while(!s.empty()) {
        int u = s.top().first;
        int p = s.top().second;

        if(vis[u]) {
            s.pop();
            continue;
        }
        vis[u] = 1; 
        for (int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            if(v == p) continue;
            //find max diameter possible
            int d = data[v].d;
            int D = data[v].D;
            if(d + D + 1 > mx) {
                mx = d + D + 1;
                dv = v;
                du = u;
            }
            
            //find min diameter possible
            long long curD = max(data[v].d, data[v].D);
            curD = max(curD, (data[v].d + 1) / 2 + (data[v].D + 1) / 2 + 1);

            if(curD < mn) {
                mn = curD;
                mdu = u;
                mdv = v;
            }
            s.push({v, u});
        }
    }
}

int bfs(int ini, int x) {
    queue<pair<int,int> > q;
    memset(way, -1, sizeof way);
    memset(vis, 0, sizeof vis);
    q.push({ini, 0});
    int cur = -1;
    int id = -1;
    while(!q.empty()) {
        int u = q.front().first;
        int c = q.front().second;
        q.pop();
        if(vis[u]) continue;
        if(c > cur) {
            cur = c;
            id = u;
        }
        vis[u] = 1;
        for (int v: G[u]) {
            if(!vis[v] and v != x) {
                way[v] = u;
                q.push({v, c + 1});
            }
        }
    }
    return id;
}

void print(int ans, int a, int b, int c, int d) {
    cout << ans << " " << a << " " << b << " " << c << " " << d << "\n";
}

int main() {
    mx = 0, mn = 1e9;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1);
    dfs2(1);
    dfs3(1);
    
    for (int i = 1; i <= n; ++i)
        cout << i << ": " << data[i].L << " " << data[i].D << " " << data[i].l << " " << data[i].d<< "\n";
    //min diameter
    
    //complement diameter

    long long d = (data[mdv].D + 1) / 2;
    int p1 = bfs(mdu, mdv);
    int p2 = bfs(p1, mdv);
    while(p2 != -1 and d--) p2 = way[p2];
    int c1 = p2;
    d = (data[mdv].d + 1) / 2;
    p1 = bfs(mdv, mdu);
    p2 = bfs(p1, mdu);
    while(p2 != -1 and d--) p2 = way[p2];
    int c2 = p2;
    print(mn, mdu, mdv, c1, c2);
    
    //diameter
    p1 = bfs(dv, du);
    p2 = bfs(p1, du);
    c1 = p2;

    p1 = bfs(du, dv);
    p2 = bfs(p1, dv);
    c2 = p2;
    print(mx, du, dv, c1, c2);
    return 0;
}
