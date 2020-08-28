#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,t,x,y;
    cin >> n >> m >> t;
    queue<pair<pair<int,int> , int> > q;
    set<pair<int,int> > s, vis;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        q.push({{x,y},0});
    }

    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        s.insert({x,y});
    }
    int ans = 0;
    while(!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        int dt = q.front().second;
        q.pop();
        if(s.count({x,y}) or dt > t or vis.count({x,y})) continue;
        ans++;
        vis.insert({x,y});
        for (int i = 0; i < 4; ++i) 
            q.push({{dx[i] + x, dy[i] + y}, dt + 1});
    }
    cout << ans << "\n";
    return 0;
}

