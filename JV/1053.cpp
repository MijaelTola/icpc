#include <bits/stdc++.h>

using namespace std;

int G[30];
int vis[30];

void dfs(int u, const vector<vector<int> > &G) {
    if(vis[u]) return;
    vis[u] = 1;
    for (int v: G[u])
        dfs(v, G);
}

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        char e;
        cin >> e;
        
        int n = e - 'A' + 1;

        vector<vector<int> > G(n + 10);
        string s;

        cin.ignore();

        while(1) {
            getline(cin,s);

            if(s == "") break;
            G[s[0] - 'A'].push_back(s[1] - 'A');
            G[s[1] - 'A'].push_back(s[0] - 'A');
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if(!vis[i]) {
                dfs(i, G);
                ans++;
            }
        }
        
        cout << ans << "\n";

        if(t) cout << "\n";
    }
    return 0;
}

