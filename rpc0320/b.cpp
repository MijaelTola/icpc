#include <bits/stdc++.h>

using namespace std;

int t[400010];
int vis[400010];
vector<int> G[400010];
int needed[400010];
int cp[400010];
vector<int> st;

int main() {

    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &t[i], &needed[i]);
        for (int j = 0; j < needed[i]; ++j) {
            int x;
            scanf("%d", &x);
            G[x].push_back(i);
        }
        cp[i] = needed[i];
    }
    
    priority_queue<pair<int,int> > q;
    queue<int> q2;

    for (int i = 1; i <= n; ++i) 
        if(needed[i] == 0) q2.push(i);
    
    
    while(!q2.empty()) {
        int id = q2.front();
        q2.pop();
        st.push_back(id);
        for (int v: G[id]) {
            cp[v]--;
            if(cp[v] == 0)
                q2.push(v);
        }
    }

    for (int i = st.size() - 1; i >= 0; i--) {
        int u = st[i];
        //cout << u << "\n";
        for (int v: G[u]) {
            t[u] = max(t[u], t[v]);
        }
    }


    //for (int i = 1; i <= n; ++i)
        //cout<< i << " " << t[i] << "\n";

    for (int i = 1; i <= n; ++i) 
        if(needed[i] == 0) q.push({t[i], i});
    int ans = 0;
    int cur = 0;
    while(!q.empty()) {
        int dt = q.top().first;
        int id = q.top().second;
        q.pop();
        ans = max(ans, cur + dt);
        cur++;
        for (int v: G[id]) {
            needed[v]--;
            if(needed[v] == 0)
                q.push({t[v], v});
        }
    }

    printf("%d\n", ans);
        
    return 0;
}

