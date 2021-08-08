#include <bits/stdc++.h>

using namespace std;

int n,k;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
vector<pair<int,int> > v[10000];
int dp[2510][2510];

int main() {

    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            v[x].push_back({i,j});
        }
    }

    auto dis = [&] (auto a, auto b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };
    
    for (int i = k - 1; i >= 1; i--) {
        for (int j = 0; j < (int)v[i].size(); ++j) {
            dp[i][j] = 1e9;
            for (int l = 0; l < (int)v[i + 1].size(); ++l) {
                dp[i][j] = min(dp[i][j], dp[i + 1][l] + dis(v[i][j], v[i + 1][l]));
            }
        }
    }


    int ans = 1e9;

    for (int i = 0; i < (int)v[1].size(); ++i)
        ans = min(ans, dp[1][i]);
    
    if(ans == 1e9) return cout << "-1\n", 0;
    cout << ans << "\n";

    return 0;
}

