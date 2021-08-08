#include <bits/stdc++.h>

using namespace std;

int vis[1010];

int main() {

    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    for (int &x: v) {
        cin >> x;
        if(x == 8240) cout << "tiene\n";
    }

    sort(v.rbegin(), v.rend());

    int dw = k;
    long long ans = 0;

    priority_queue<pair<int,int> > q;
    
    int cnt = 0;
    for (int i = 0; i < n and dw - v[i] >= 0; ++i) {
        dw -= v[i];
        ans += v[i];
        vis[i] = 1;
        q.push({v[i], i});
        cnt++;
    }

    

    while(!q.empty()) {
        auto [val, id] = q.top();
        q.pop();

        multiset<int> s;

        for (int i = 0; i < n; ++i) {
            if(!vis[i])
                s.insert(v[i]);
        }

        long long cur = ans;
        int id2 = -1;
        for (int i = 0; i < n; ++i) {
            if(vis[i]) continue;
            s.erase(s.lower_bound(v[i]));
            long long nans = ans - val + v[i];
            int left = k - nans;
            
            if(left < *s.begin() and nans < cur) {
                ans = min(ans, nans);
                cur = nans;
                id2 = i;
            }

            s.insert(v[i]);
        }
        
        cout << id2 << "\n";
        exit(0);
        if(cur < ans and id2 != -1) {
            ans = cur;
            vis[id] = 0;
            vis[id2] = 1;
            q.push({v[id2], id2});
        }
    }

    cout << ans << "\n";

    return 0;
}
