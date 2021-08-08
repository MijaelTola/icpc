#include <bits/stdc++.h>

using namespace std;

int w[5];
int l[5];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> w[i];

        for (int i = 0; i < n; ++i)
            cin >> l[i];

        vector<tuple<int,int, int> > v;
        for (int i = 0; i < n; ++i) 
            v.push_back({i, w[i], l[i]});
    
        queue<pair<vector<tuple<int,int,int> >, int> > q;
        q.push({v, 0});
        
        set<vector<pair<int,int> >> vis;
        while(!q.empty()) {
            auto [v, c] = q.front();
            q.pop();

            sort(v.begin(), v.end());
        
            vector<pair<int,int> > cur;

            vector<int> vv;
            for (int i = 0; i < n; ++i) {
                auto [a,b,z] = v[i];
                cur.push_back({b,a});
                vv.push_back(b);
            }

            bool flag = 1;

            for (int i = 1; i < n; ++i) {
                flag &= cur[i].first > cur[i - 1].first and cur[i].second != cur[i - 1].second;
            }

            if(flag) {
                cout << c << "\n";
                break;
            }
            
            if(vis.count(cur)) continue;
            vis.insert(cur);
            for (int i = 0; i < n; ++i) {
                auto vv = v;
                auto [a, b, z] = v[i];
                if(a + z <= 100) {
                    vv[i] = {a + z, b, z};
                    q.push({vv, c + 1});
                }
            }
        }
    }
    return 0;
}

