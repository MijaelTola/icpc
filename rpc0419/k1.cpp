#include <bits/stdc++.h>

using namespace std;

string a,b;
int sz;
int pre[20][20];
int dp[20][1 << 20];

bool ver(int x, int y) {
    for (int i = 0; i < sz; ++i) {
        if(x & (1 << i) and y & (1 << i)) return 0;
    }
    return 1;
}

int f(int pos, int mask) {
    if(pos == sz) {
        if(mask == (1 << sz) - 1) return 0;
        return 10000;
    }
    int &ans = dp[pos][mask];
    if(ans != -1) return ans;
    ans = 10000;
    
    ans = min(ans, f(pos + 1, mask));
    for (int i = 0; i < sz; ++i) {
        int cur = mask | pre[pos][i];
        int cnt = __builtin_popcount(cur);
        int l = __builtin_popcount(mask);
        int r = __builtin_popcount(pre[pos][i]);
        if(l + r == cnt and cnt) 
            ans = min(ans, f(pos + r, mask | pre[pos][i]) + 1);
    }
    return ans;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> a >> b;
    sz = a.size();
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            int l = i;
            int r = j;
            int cur = 0;
            int cur2 = 0;
            while(a[l] == b[r] and l < sz and r < sz) {
                cur |= (1 << l);
                cur2 |= (1 << r);
                l++;
                r++;
            }
            pre[j][i] = cur;
        }
    }

    cout << f(0,0) - 1 << "\n";
    return 0;
}

