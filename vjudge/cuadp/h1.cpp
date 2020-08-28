#include <bits/stdc++.h>

using namespace std;

int n,k;
int a[110];
int b[110];

//sa/sb = k 
//sa = k * sb
//
//a1 + a2 + a3 + ... = k * (b1 + b2 + b3 + ...)
//a1 + a2 + a3 + ... = k * b1 + k * b2  + k * b3 * ....

//a1 - k * b1 + a2 - k * b2 + a3 - k * b3 ... = 0
//sa - k * (sb)
//
//100 * 100000
//10^10
//10 ^ 7

//0 = 100000 | 100000 = 200000
//-100000 = 0

int mid = 0;
int dp[110][200010];

int f(int pos, int sum) {
    if(pos == n) {
        if(sum == mid) return 0;
        return -1e9;
    }
    
    if(dp[pos][sum] != -1) return dp[pos][sum];
    int ans = -1e9;
    
    int val = sum - mid;
    ans = max(ans, f(pos + 1, val + mid));
    ans = max(ans, f(pos + 1, (val + a[pos] - k * b[pos]) + mid) + a[pos]);

    return dp[pos][sum] = ans;
}

int main() {

    memset(dp, -1, sizeof dp);
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    if(f(0, mid) <= 0) cout << "-1\n";
    else cout << f(0,mid) << "\n";;
    return 0;
}

