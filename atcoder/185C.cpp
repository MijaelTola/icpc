#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[210][15];

long long f(int pos, int cur) {
    if(pos >= n) return 0;
    if(cur == 11) return 1;
    long long &ans = dp[pos][cur];

    if(ans != -1) return ans;
    ans = 0;
    ans += f(pos + 1, cur + 1);
    ans += f(pos + 1, cur);

    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    
    cin >> n;
    cout << f(0,0) << "\n";
   
    return 0;
}

