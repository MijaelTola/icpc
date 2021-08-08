#include <bits/stdc++.h>

using namespace std;

int n;
int cnt[21][21];
long long dp[(1 << 20) + 10];
vector<int> v[21];

int main() {
    
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[x].push_back(i);
    }

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if(i == j or v[i].empty() or v[j].empty()) continue;
            int a = 0;
            for (int cur: v[i]) {
                while(a < (int)v[j].size() and v[j][a + 1] < cur) a++;
                if(a > v[j][a])
                    cnt[i][j] += a;
            }

        }
    }
    
    for (int i = 0; i < (1 << 20) + 10; ++i)
        dp[i] = 1e12;

    dp[(1 << n) - 1] = 0;
    for (int i = (1 << n) - 2; i >= 0; i--) {
        for (int j = 0; j < 20; ++j) {
            if(i & (1 << j)) continue;
            long long cur = 0;
            for (int k = 0; k < 20; ++k) {
                if(j == k) continue;
                if(i & (1 << k))
                    cur += cnt[j][k];
            }
            dp[i] = min(dp[i], dp[i | (1 << j)] + cur);
        }
    }

    cout << dp[0] << "\n";

    return 0;
}

