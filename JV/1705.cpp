#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int dp[100010];
int f(int x) {
    if(x == 0) return 1;
    int &ans = dp[x];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = 1; i <= x; i += 2)
        if(x - i >= 0) 
            ans = (ans + f(x - i)) % mod;
        
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}

