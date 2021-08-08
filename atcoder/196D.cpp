#include <bits/stdc++.h>

using namespace std;

int h,w,a,b;

long long dp[(1 << 17) + 10][20];

long long f(int mask, int da) {
   
    if(da == a)  
        return 1;

    long long &ans = dp[mask][da];
    if(ans != -1) return ans;

    ans = 0;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int pos = w * i + j;
            int next = w * i + j + 1;
            if(!(mask & (1 << pos)) and j + 1 < w and !(mask & (1 << next))) {
                ans += f(mask | (1 << pos) | (1 << next), da + 1);
            }
            next = w * (i + 1) + j;
            if(!(mask & (1 << pos)) and i + 1 < h and !(mask & (1 << next))) {
                ans += f(mask | (1 << pos) | (1 << next), da + 1);
            }
        }
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> h >> w >> a >> b;

    long long ft = 1;

    for (int i = 1; i <= a; ++i)
        ft *= i;

    cout << f(0, 0) / ft << "\n";
    return 0;
}

