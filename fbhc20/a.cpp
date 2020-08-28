#include <bits/stdc++.h>

using namespace std;

vector<int> G[55];
bool vis[55];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    string in,out;
    cin >> t;
    
    int k = 1;
    while(t--) {
        int n;
        cin >> n >> in >> out;
        for (int i = 0; i < n; ++i)
            G[i].clear();
        for (int i = 0; i < n; ++i) {
            if(out[i] == 'Y') {
                if(i and in[i - 1] == 'Y') 
                    G[i].push_back(i - 1);

                if(i + 1 < n and in[i + 1] == 'Y') 
                    G[i].push_back(i + 1);
            }
        }

        cout << "Case #" << k++ << ":\n";
        for (int i = 0; i < n; ++i) {
            memset(vis, 0, sizeof vis);
            queue<int> q;
            q.push(i);

            while(!q.empty()) {
                int u = q.front();
                q.pop();
                vis[u] = 1;
                for (int v: G[u]) {
                    if(!vis[v]) {
                        q.push(v);
                    }
                }
            }

            for (int j = 0; j < n; ++j)
                if(vis[j]) cout << "Y";
                else cout << "N";
            cout << "\n";
        }
    }
    return 0;
}

