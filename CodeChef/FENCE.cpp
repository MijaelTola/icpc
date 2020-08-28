#include <bits/stdc++.h>

using namespace std;

int t,n,m,k,x,y;
vector<pair<int,int> > v;
set<pair<int,int> > s;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool ver(int x, int y) {
    return x >= 0 and y >= 0 and x < n and y < m and s.count({x,y});
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while(t--) {
        v.clear();
        s.clear();
        cin >> n >> m >> k;
        for (int i = 0; i < k; ++i) {
            cin >> x >> y;
            x--,y--;
            v.push_back(make_pair(x,y));
            s.insert({x,y});
        }
    
        int ans = 0;
        for (auto p: v) {
            for (int i = 0; i < 4; ++i) {
                x = dx[i] + p.first;
                y = dy[i] + p.second;
                if(!ver(x,y)) ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}

