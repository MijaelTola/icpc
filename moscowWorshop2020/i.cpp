#include <bits/stdc++.h>

using namespace std;

int n1,n2,m;
vector<int> G[1010];
int vis[1010];
int mark[1010];
int mark2[1010];


bool dfs(int u) {
    if(vis[u]) return 0;
    vis[u] = 1;
    for (int v: G[u]) {
        if(mark[v] == -1 or dfs(mark[v])) {
            mark[v] = u;
            mark[u] = v;
            return 1;
        }
    }
    return 0;
}

int mbm() {
    memset(mark, -1, sizeof mark);
    for (int i = 1; i <= n1; ++i) {
        if(mark[i] == -1) {
            memset(vis, 0, sizeof vis);
            dfs(i);
        }
    }

    int ans = 0;

    for (int i = 1; i <= n1; ++i) {
        ans += mark[i] != -1;
    }

    return ans;
}   

int main() {

    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n1 >> n2 >> m;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y + n1);
        G[y + n1].push_back(x);
    }
    
    for (int i = 1; i <= n1; ++i) {
        if(mark[i] == -1) {
            for (int j: G[i]) {
                if(mark[j] == -1) {
                    mark[i] = j;
                    mark[j] = i;
                    break;
                }
            }
        }
    }
    mbm();

    
    auto only = [] (int id) {
        for (int i = 1; i <= n1 + n2; ++i)
            mark2[i] = mark[i];

        int pl = mark[id];
        mark[pl] = -1;
        memset(vis, 0, sizeof vis);
        bool flag = dfs(mark[id]);

        for (int i = 1; i <= n1 + n2; ++i)
            mark[i] = mark2[i];
       
        return flag;
    };

    for (int i = 1; i <= n1; ++i) {
        if(mark[i] == -1) cout << "P";
        else {
            if(!only(i)) cout << "N";
            else cout << "P";
        }
    }
    cout << "\n";
    for (int i = n1 + 1; i <= n1 + n2; ++i) {
        if(mark[i] == -1) cout << "P";
        else {
            if(!only(i)) cout << "N";
            else cout << "P";
        }
    }
    cout << "\n";


    return 0;
}
