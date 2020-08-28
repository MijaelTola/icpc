#include <bits/stdc++.h>

using namespace std;

string s,t, res = "";
int dp[3010][3010];

int f(int i, int j) {
    if(i == (int)s.size() or j == (int)t.size()) return 0;
    int &ans = dp[i][j];
    if(ans != -1) return ans;
    ans = 0;
    if(s[i] == t[j]) ans = max(ans, f(i + 1, j + 1) + 1);
    ans = max(ans, f(i + 1, j));
    ans = max(ans, f(i, j + 1));
    return ans;
}

void r(int i, int j) {
    if(i == (int)s.size() or j == (int)t.size()) return;
    int ans = 0;
    int id = -1;
    if(s[i] == t[j]) {
        if(f(i + 1, j + 1) + 1 > ans) {
            ans = f(i + 1, j + 1) + 1;
            id = 0;
        }
    }
    
    if(f(i + 1, j) > ans) {
        ans = f(i + 1, j);
        id = 1;
    }

    if(f(i, j + 1) > ans) {
        ans = f(i, j + 1);
        id = 2;
    }
    
    if(id == 0) {
        res += s[i];
        r(i + 1, j + 1);
        return;
    }

    if(id == 1) r(i + 1, j);
    if(id == 2) r(i, j + 1);
    
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> s >> t;
    
    f(0, 0);
    r(0, 0);
    cout << res << "\n";
    return 0;
}

