#include <bits/stdc++.h>

using namespace std;

long long a,b,k;
long long dp[33][33];

long long f(int a, int b) {
    if(a + b == 0) {
        return 1;
    }

    long long &ans = dp[a][b];
    if(ans != -1) return ans;
    ans = 0;
    if(a) ans += f(a - 1, b);
    if(b) ans += f(a, b - 1);
    return ans;
}

void r(int a, int b, long long k) {
    if(a + b == 0) return;


    if(a and f(a - 1, b) >= k) {
        cout << "a";
        r(a - 1, b, k);
    } else if(b) {
        cout << "b";
        r(a, b - 1, k - f(a - 1, b));
    }

}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> a >> b >> k;
    f(a,b);
    r(a,b,k);
    cout << "\n";
    
    return 0;
}

