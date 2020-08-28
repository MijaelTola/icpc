#include <bits/stdc++.h>

using namespace std;

int n,p,q;
int dp[310][30500];
const int mod = 1e9+7;

int f(int pos, int w) {
    if(w == 0) return 1;
    if(pos == 0) return 0;
    int &ans = dp[pos][w];
    if(ans != -1) return ans;
    ans = 0;
    if(w - pos >= 0) ans = (ans + f(pos - 1, w - pos)) % mod;
    ans = (ans + f(pos - 1, w)) % mod;
    return ans;
}


int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &n, &p);
        printf("%d\n", f(n,p));
    }
    return 0;
}

