#include <bits/stdc++.h>

using namespace std;

struct node {
    long long l,d,L,D, mx, mx2, mx3;
    int imx, imx2, imx3;
    long long dmx, dmx2, dmx3;
    int idmx, idmx2, idmx3;
};

int n;
long long du,dv;
long long mdu,mdv;
long long mx,mn;
vector<int> G[500011];
node data[500011];
bool vis[500011];
int way[500011];


int bfs(int x, int p) {
    memset(way,-1,sizeof way);
    queue<pair<int,int> > q;
    q.push({x,x});
    way[x] = x;
    int mx = -1, id = -1;
    while(!q.empty()) {
        int u = q.front().first;
        int c = q.front().second;
        q.pop();
        if(c > mx) {
            mx = c;
            id = u;
        } 
        for (int v: G[u]) {
            if(v == p or way[v] != -1) continue;
            way[v] = u;
            q.push({v, c + 1});
        }
    }
    return id;
}

void dfs(int ini) {
    memset(vis, 0, sizeof vis);
    stack<pair<int,int> > st;
    st.push({ini,ini});
    while(!st.empty()) {
        int u = st.top().first;
        int p = st.top().second;
        data[u].l = 0;
        data[u].d = 0;
        data[u].mx3 = data[u].mx2 = data[u].mx = -1;
        data[u].imx3 = data[u].imx2 = data[u].imx = -1;
        data[u].dmx3 = data[u].dmx2 = data[u].dmx = -1;
        data[u].idmx3 = data[u].idmx2 = data[u].idmx = -1;

        if(vis[u] == 1) {
            st.pop();
            for (int i = 0; i < (int)G[u].size(); ++i) {
                int v = G[u][i];
                if(v == p) continue;
                data[u].l = max(data[u].l, data[v].l + 1); //deepest
                if(data[v].l > data[u].mx) {
                    data[u].imx3 = data[u].imx2;
                    data[u].mx3 = data[u].mx2;
                    data[u].imx2 = data[u].imx;
                    data[u].mx2 = data[u].mx;
                    data[u].imx = i;
                    data[u].mx = data[v].l;
                } else if(data[v].l > data[u].mx2) {
                    data[u].imx3 = data[u].imx2;
                    data[u].mx3 = data[u].mx2;
                    data[u].imx2 = i;
                    data[u].mx2 = data[v].l;
                } else if(data[v].l > data[u].mx3) {
                    data[u].imx3 = i;
                    data[u].mx3 = data[v].l;
                }

                if(data[v].d > data[u].dmx) {
                    data[u].idmx2 = data[u].idmx;
                    data[u].dmx2 = data[u].dmx;
                    data[u].idmx = i;
                    data[u].dmx = data[v].d;
                } else if(data[v].d > data[u].dmx2) {
                    data[u].idmx2 = i;
                    data[u].dmx2 = data[v].d;
                }
            }
            data[u].d = max(data[u].d, data[u].dmx); 
            data[u].d = max(data[u].d, data[u].mx + 1); //u is an endpoint of ds
            if(G[u].size() >= 2) data[u].d = max(data[u].d, data[u].mx + data[u].mx2 + 2);//throught u

        }

        vis[u] = 1;

        for (int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            if(v != p and !vis[v]) {
                st.push({v,u});
            }
        }
    }
}

void dfs2(int ini) {
    memset(vis, 0, sizeof vis);
    stack<pair<int,int> > st;
    st.push({ini,ini});
    while(!st.empty()) {
        int u = st.top().first;
        int p = st.top().second;
        if(vis[u]) {
            st.pop();
        }
        vis[u] = 1;
        for (int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            if(v == p or vis[v]) continue;
            data[v].L = data[u].L + 1;
            if(data[u].imx != i) data[v].L = max(data[v].L, data[u].mx + 1);
            else if ((int) G[u].size() >= 2) data[v].L = max(data[v].L, data[u].mx2 + 1);

            //v is not part of D
            data[v].D = data[u].D;
            if(data[u].idmx != i) data[v].D = max(data[v].D, data[u].dmx);
            else if( (int) G[u].size() >= 2) data[v].D = max(data[v].D, data[u].dmx2);
            //v is an endpoint
            data[v].D = max(data[v].D, data[v].L); 

            if(i != data[u].imx) data[v].D = max(data[v].D, data[u].mx + 2 + data[u].L);
            else if((int) G[u].size() >= 2) data[v].D = max(data[v].D, data[u].mx2 + 2 + data[u].L);
            //child with child
            if((int)G[u].size() >= 3) {
                if(i == data[u].imx) data[v].D = max(data[v].D, data[u].mx2 + data[u].mx3 + 2);
                else if(i == data[u].imx2) data[v].D = max(data[v].D, data[u].mx + data[u].mx3 + 2);
                else if(i == data[u].imx3) data[v].D = max(data[v].D, data[u].mx2 + data[u].mx + 2);
                else data[v].D = max(data[v].D, data[u].mx + data[u].mx2 + 2);
            }
            st.push({v,u});
        }
    }
}

void dfs3(int ini) {
    memset(vis, 0, sizeof vis);
    stack<pair<int,int> > st;
    st.push({ini,ini});
    while(!st.empty()) {
        int u = st.top().first;
        int p = st.top().second;
        if(vis[u]) st.pop();
        vis[u] = 1;
        for (int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            if(v == p or vis[v]) continue;
            st.push({v,u});
            if(data[v].D + data[v].d + 1 > mx) {
                mx = data[v].D + data[v].d + 1;
                du = u, dv = v;
            }
            long long dMax = data[v].d;
            dMax = max(dMax, data[v].D);
            dMax = max(dMax, (data[v].D + 1)/ 2 + (data[v].d + 1) / 2 + 1);

            if( dMax < mn ) {
                mn = dMax; 
                mdu = u, mdv = v;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    mx = 0, mn = 1e11;
    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1);
    data[1].D = 0;
    data[1].L = -1;
    dfs2(1);
    dfs3(1);
    
    /*
    for (int i = 1; i <= n; ++i) {
        cout << i << ": \n";
        cout << data[i].l << " " << data[i].mx << " " << data[i].mx2 << " " << data[i].mx3 << "\n";
        if(data[i].imx3 != -1)cout << data[G[i][data[i].imx3]].l << "\n";
        else cout << "no\n";
        cout << "\n";
    }*/

    for (int i = 1; i <= n; ++i) {
        cout << i << ": " << data[i].L << " " << data[i].D << " | " << data[i].l << " " << data[i].d <<"\n";
    }
    int p1 = bfs(mdu, mdv);
    p1 = bfs(p1, mdv);
    int d = (data[mdv].D + 1) / 2;
    while(d-- and p1 != -1) p1 = way[p1];
    int p2 = bfs(mdv, mdu);
    p2 = bfs(p2, mdu);
    d = (data[mdv].d + 1) / 2;
    while(d-- and p2 != -1) p2 = way[p2];
    cout << mn << " " << mdu << " " << mdv  << " " << p1 << " " << p2<< "\n";
    p1 = bfs(du, dv);
    p1 = bfs(p1, dv);
    p2 = bfs(dv, du);
    p2 = bfs(p2, du);
    cout << mx << " " << du << " " << dv   << " " << p1  << " " << p2  << "\n"; 
    return 0;
}

