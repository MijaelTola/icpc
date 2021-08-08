#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,d;
    cin >> n >> d;
    

    vector<pair<int,int> > v(n);

    for (auto &p: v)
        cin >> p.first >> p.second;

    
    long long ans = 0;

    priority_queue<pair<int,int> > a;

    for (int i = 0; i < n; ++i) {
        auto [x,y] = v[i];
        a.push({-y, i + d});
        
        while(a.top().second <= i) 
            a.pop();
        ans += x * -a.top().first;
    }

    cout << ans << "\n";

    return 0;
}

