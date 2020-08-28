#include <bits/stdc++.h>

using namespace std;

queue<int> v[300010];
bool vis[300010];

int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    int n,t;
    cin >> n >> t;

    queue<int> q;
    
    int ans = 0;
    int tm = 0;
    int cur = 0;

    while(t--) {
        int c,x;
        cin >> c >> x;
        if(c == 1) {
            v[x].push(tm);
            q.push(tm);
            ans++;
            tm++;
        } 

        if(c == 2) {
            while(!v[x].empty()) {
                if(!vis[v[x].front()]) ans--;
                vis[v[x].front()] = 1;
                v[x].pop();
            }
        }

        if(c == 3) {
            while(!q.empty() and cur < x) {
                int a = q.front();
                q.pop();
                if(!vis[a]) ans--, vis[a] = 1;
                cur++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

