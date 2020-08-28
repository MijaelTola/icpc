#include <bits/stdc++.h>

using namespace std;

int v[1010];

int dp[1010][1010][2];
int f(int l, int r, int t) {
    if(l >= r) return 0;
    int &ans = dp[l][r][t];
    if(ans != -1) return ans;

    if(t) return ans = max(f(l + 1, r, !t) + v[l], f(l, r - 1, !t) + v[r]);
    
    if(v[l] >= v[r]) return ans = f(l + 1, r, !t);
    else return ans = f(l, r - 1, !t);
}

int main() {
    
    int n;

    int k = 1;
    while(cin >> n and n) {
        memset(dp, -1, sizeof dp);
        int total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            total += v[i];
        }
        total -= f(0, n - 1, 1);
        int cur = f(0, n - 1, 1);
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", k++, cur - total);
    }
    return 0;
}

