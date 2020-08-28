#include <bits/stdc++.h>

using namespace std;
int n,k;

long long dp[1000010];
long long f(int pos){
    if(n - pos <= k ) return 1;
    if(dp[pos] != -1) return dp[pos];
    long long ans = 0;
    for (int i = 1; i <= k; ++i)
        ans += f(pos + i);
    //ans += f(pos + 1);
    return dp[pos] = ans % 123456789;
}
int main(){
    memset(dp, -1,sizeof dp);
    cin >> n >> k;
    cout << f(0) + 1<< "\n";
    return 0;
}

