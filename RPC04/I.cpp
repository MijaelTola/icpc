#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        vector<pair<int,int> > v;
        priority_queue<int> q;
        int n,m;
        scanf("%d %d",&n,&m);
        for (int i = 0; i < m; ++i){
            int x,y;
            scanf("%d %d",&x, &y);
            v.push_back(make_pair(x,y));
        }
        sort(v.begin(),v.end());
        q.push(-0);
        int ans = 0;
        for (int i = 0; i < (int)v.size(); ++i){
            int ini = v[i].first;
            int endd = v[i].second;
            if(-q.top() > ini) ans += q.size();
            else while(-q.top() <= ini and !q.empty())q.pop();
            q.push(-endd);
        }
        printf("%d\n",ans);
    }
    return 0;
}

