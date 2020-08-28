#include <bits/stdc++.h>

using namespace std;

int v[500010];
int nodes[500010];
vector<int> G[500010];

int main(){
    
    int n;
    while(scanf("%d",&n) != EOF){
        priority_queue<int> q;
        for (int i = 0; i < 500010; ++i){
            nodes[i] = 0;
            G[i].clear();
            v[i] = 0;
        }

        for (int i = 0; i < n - 2; ++i)
            scanf("%d", v + i);

        for (int i = 0; i < n - 2; ++i)
            nodes[v[i]]++;

        for (int i = 1; i <= n; ++i)
            if(!nodes[i]) q.push(-i);

        bool flag = 0;
        for (int i = 0; i < n - 2; ++i){
            int c = -q.top();
            int cur = v[i];
            q.pop();
            G[min(c,cur)].push_back(max(cur,c));
            nodes[cur]--;
            if(!nodes[cur]) q.push(-cur);
        }
        int u = -q.top(); q.pop();
        int r = -q.top(); q.pop();

        G[min(u,r)].push_back(max(u,r));
        for (int i = 1; i <= n; ++i){
            sort(G[i].begin(),G[i].end());
            for (int j = 0; j < (int)G[i].size(); ++j)
                printf("%d %d\n",i,G[i][j]);
        }

    }
    return 0;
}

