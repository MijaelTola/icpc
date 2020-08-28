#include <bits/stdc++.h>

using namespace std;

int n;
int v[100010][3];
int dp[100010][3];

int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> v[i][j];


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(i) dp[i][j] = max(dp[i][j], dp[i - 1][(j + 3 - 1) % 3]);
            if(i) dp[i][j] = max(dp[i][j], dp[i - 1][(j + 1) % 3]);
            dp[i][j] += v[i][j];
        }
    }
    
    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << "\n";
    return 0;
}

