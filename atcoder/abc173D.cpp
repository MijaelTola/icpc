#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n);

    for (int &x: v)
        cin >> x;

    sort(v.rbegin(), v.rend());

    priority_queue<pair<int, pair<int,int> > > q;
    long long ans = 0;
    
    for (int i = 0; i < n; ++i) {
        int x = v[i];
        if(q.empty()) {
            q.push({x, {x, x}});
        } else {
            ans += q.top().first;
            int a = q.top().second.first;
            int b = q.top().second.second;
            q.pop();
            q.push({min(a,x), {x, a}});
            if(b != -1) q.push({min(b,x), {x, b}});
        }
    }
    cout << ans << "\n";

    return 0;
}

