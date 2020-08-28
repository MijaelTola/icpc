#include <bits/stdc++.h>

using namespace std;

int n;
queue<int> q[1001];
bool vis[1001];

int f() {
    memset(vis, 0, sizeof vis);
    bool flag = 0;
    for (int i = 1; i <= n; ++i) {
        if(vis[i]) continue;
        if(q[i].empty()) continue;
        int x = q[i].front();
        if(q[x].empty()) continue;
        if(q[x].front() == i and !vis[i] and !vis[x]) {
            flag = 1;
            vis[x] = vis[i] = 1;
            q[x].pop();
            q[i].pop();
        }
    }
    if(!flag) return -1;
    for (int i = 1; i <= n; ++i)
        if(q[i].size()) return 1;
        
    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            int x;
            scanf("%d", &x);
            q[i].push(x);
        }
    }

    int ans = 0;
    int ini = 1;
    int lim = 1000010;
    while(ini == 1 and lim--) ini = f(), ans++;
    if(ini == -1) puts("-1");
    else printf("%d\n", ans);
    return 0;
}

