#include <bits/stdc++.h>

using namespace std;

int dx[300010];
int dy[300010];

int main() {
    
    int h,w,m;
    cin >> h >> w >> m;
    
    set<pair<int,int> > s;
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        s.insert({x,y});
        dx[x]++;
        dy[y]++;
    }
    
    vector<pair<int,int> > a,b;

    for (int i = 0; i <= 300000; ++i) {
        a.push_back({dx[i], i});
        b.push_back({dy[i], i});
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;

    for (int i = 0; i < 300010; ++i) {
        int total = a.back().first + b[i].first;
        if(s.count({a.back().second, b[i].second})) total--;
        int total2 = b.back().first + a[i].first;
        if(s.count({a[i].second, b.back().second})) total2--;
        ans = max({ans, total, total2});
    }

    cout << ans << "\n";
    return 0;
}

