#include <bits/stdc++.h>

using namespace std;


int main() {

    int t,n,x,y;
    scanf("%d", &t);
    while(t--) { 
        map<multiset<pair<int,int> >, int> mp;
        vector<pair<int,int> > v;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &x, &y);
            v.emplace_back(min(x,y), max(x,y));
        }
        
        for (int i = 0; i < n; ++i) {
            multiset<pair<int,int>> cur;
            for (int j = i; j < n; ++j) {
                cur.insert({v[j]});
                mp[cur]++;
            }
        }
        
        long long ans = 0;
        for (auto p: mp) {
            ans += (p.second * (p.second - 1)) / 2;
        }

        printf("%lld\n", ans);
    }
    return 0;
}

