#include <bits/stdc++.h>

using namespace std;

int n,k;
long long dp[65][65][3800];

long long f(int pos, int curB, int total) {
    if(pos == n) return total == k;
    long long &ans = dp[pos][curB][total];
    if(ans != -1) return ans;
    ans = 0;
    ans += f(pos + 1, curB + 1, total);
    ans += f(pos + 1, curB, total + curB);
    return ans;
}

void r(int pos, int curB, int total, long long find) {
    if(pos == n) return;

    if(f(pos + 1, curB, total + curB) >= find) {
        cout << "A";
        r(pos + 1, curB, total + curB, find);
    } else {
        find -= f(pos + 1, curB, total + curB);
        cout << "B";
        r(pos + 1, curB + 1, total, find);
    }
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    
    long long total = f(0,0,0);
    
    if(total & 1) {
        r(0,0,0, total / 2 + 1);
        cout << "\n";
    } else {
        r(0,0,0, total / 2);
        cout << "\n";
        r(0,0,0, total / 2 + 1);
        cout << "\n";
    }
    return 0;
}

