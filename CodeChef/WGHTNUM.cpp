#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
long long n;
int w;
int dp[101000][310][10];
int f(int pos,int sum, int last) {
    if(pos == n) return sum == w;
    if(dp[pos][sum][last] != -1) return dp[pos][sum][last];
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        char l = i + '0';
        ans = (ans + f(pos + 1, sum + (i - last), i)) % mod;
    }
    return dp[pos][sum][last] = ans;
}

int modpow(long long a, long long b, long long n) {
    long long  x = 1, y = a;
    while(b > 0) {
        if(b % 2 == 1) {
            x = (x * y) % n;
        }
        y = (y * y) % n;
        b /= 2;
    }
    return x % n;

}
int p[] = {0,1,7,6,5,4,3,2,1};
int main(){   
    ios::sync_with_stdio(false); cin.tie(0);
    int t; 
    cin >> t;
    memset(dp,-1,sizeof dp);
    while(t--) {
        cin >> n >> w;
        int ans = 0;
        long long pw = modpow(10,(n - 2) % (mod - 1),mod);
        cout << (pw * p[w]) % mod << "\n";
    }
    return 0;
}

