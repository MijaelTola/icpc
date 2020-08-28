#include <bits/stdc++.h>

using namespace std;

int n,w,h;
vector<pair<pair<int,int>, int> > v,b;
int dp[5010];
int f(int pos) {
    if(pos + 1 == (int)b.size()) return 0;

    int &ans = dp[pos];

    if(ans != -1) return ans;

    ans = 0;
    for (int i = pos + 1; i < (int)b.size(); ++i) {
        if(b[pos].first.second < b[i].first.second
                and b[pos].first.first < b[i].first.first) {
            ans = max(ans, f(i) + 1);
        }
    }
    return ans;
}

void r(int pos) {
    if(pos + 1 == (int)b.size()) return;

    int ans = 0;
    int id = -1, res = -1;
    for (int i = pos + 1; i < (int)b.size(); ++i) {
        if(b[pos].first.second < b[i].first.second
                and b[pos].first.first < b[i].first.first) {
            if(f(i) + 1 > ans) {
                ans = f(i) + 1;
                id = i;
                res = b[i].second + 1;
            }
        }
    }
    
    if(id != -1) {
        cout << res << " ";
        r(id);
    }
}

int main() {

    memset(dp, -1, sizeof dp);
    cin >> n >> w >> h;

    
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({{x,y}, i});
    }

    sort(v.begin(), v.end());

    b.push_back({{w,h}, -1});

    for (auto t: v)
        b.push_back(t);

    cout << f(0) << "\n";

    r(0);
    cout << "\n";
    return 0;
}

