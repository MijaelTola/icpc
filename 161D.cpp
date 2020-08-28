#include <bits/stdc++.h>

using namespace std;

int n = 2, k;
long long dp[10][10][2];
long long a = 0;


int f(int pos, int last, bool flag) {
    if(pos == n) {
        if(flag) return 1;
        return 0;
    }
    
    long long &ans = dp[pos][last][flag];
    if(ans != -1) return ans;
    ans = 0;

    for (int i = 0; i < 10; ++i) {
        if(abs(i - last) <= 1 or !flag) {
            ans += f(pos + 1, i, flag | i);
        }
    }
    return ans;
}

void r(int pos, int last, bool flag) {
    if(pos == n) return;

    int ans = 0;
    int id = 0;
    int t = -1;
    
    for (int i = 0; i < 10; ++i) {
        if(abs(i - last) <= 1 or !flag) {
            if(ans + f(pos + 1, i, flag | i) >= k) {
                id = i;
                break;
            } else ans += f(pos + 1, i, flag | i);
        }
    }

    k -= ans;

    a = a * 10 + id;
    r(pos + 1, id, id | flag);
}


int main() {
    memset(dp, -1, sizeof dp);
    f(0,0,0);
    cin >> k;
    r(0,0,0);
    cout << a << "\n";
    return 0;
}

