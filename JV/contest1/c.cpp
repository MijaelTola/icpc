#include <bits/stdc++.h>

using namespace std;

int dis[10010];
int t,a,b;

int rev(int x) {
    int ans = 0;
    while(x > 0) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}

int main() {
    //revisen sus casos mi codigo esta bien !!!!!
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while(t--) {
        memset(dis, -1, sizeof dis);
        cin >> a >> b;
        queue<int> q;
        q.push(a);
        dis[a] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(dis[u] == -1) continue;
            if(u > 10000) continue;
            if(dis[u + 1] == -1) {
                dis[u + 1] = dis[u] + 1;
                q.push(u + 1);
            }
            int nv = rev(u);
            if(dis[nv] == -1) {
                dis[nv] = dis[u] + 1;
                q.push(nv);
            }
        }
        cout << dis[b]  << "\n";
    }
    return 0;
}

