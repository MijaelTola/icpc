#include <bits/stdc++.h>

using namespace std;

int v[200010];
int main() {
    
    int t;
    scanf("%d", &t);

    while(t--) {
        int n,k;
        scanf("%d %d", &n, &k);


        map<int,int> mp;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", v + i);
            mp[v[i]] = i;
        }

        vector<tuple<int,int,int>> ans;
        set<pair<int,int> > no;
        
        while(!mp.empty()) {
            auto p = *mp.begin();
            mp.erase(mp.begin());
            if(p.first == p.second) continue;
            if(v[p.first] != p.second) {
                ans.push_back({p.second, p.first, v[p.first]});
                int a = v[p.second];
                int b = v[p.first];
                int d = v[v[p.first]];
                int c = v[p.first];
                swap(v[p.second], v[p.first]);
                swap(v[p.second], v[c]);
                mp[a] = a;
                mp[b] = b;
                mp[d] = p.second;
            } else {
                no.insert({min({p.second, p.first}), max({p.second, p.first})});
            }

        }
        
        if((no.size() & 1) or (int)ans.size() > k) {
            puts("-1");
            continue;
        }
        set<pair<int,int> > vis;
        while(!no.empty()) {
            auto p = *no.rbegin();
            no.erase(p);
            if(vis.count(p)) continue;
            auto z = *no.rbegin();
            vis.insert(p);
            vis.insert(z);
            no.erase(z);
            ans.push_back({p.first, p.second, z.first});
            ans.push_back({p.first, z.second, z.first});
        }
        cout << ans.size() << "\n";
        for (auto p: ans) {
            int a,b,c;
            tie(a,b,c) = p;
            printf("%d %d %d\n", a, b,c);
        }
        
    }
    return 0;
}

