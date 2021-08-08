#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> a,b;
int dp[1010][1010];
int f(int da, int db) {
    if(da == (int)a.size() or db == (int)b.size()) {
        return (int)a.size() - da + (int)b.size() - db;
    }

    int &ans = dp[da][db];
    if(ans != -1) return ans;
    ans = 1e9;
    ans = min(ans, f(da + 1, db) + 1);
    ans = min(ans, f(da, db + 1) + 1);
    if(a[da] == b[db]) ans = min(ans, f(da + 1, db + 1));
    else ans = min(ans, f(da + 1, db + 1) + 1);
    return ans;
}

int main() {
    
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }


    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    cout << f(0, 0) << "\n";


    return 0;
}

