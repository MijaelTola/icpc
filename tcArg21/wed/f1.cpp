#include <bits/stdc++.h>

using namespace std;

int v[5010];
long long dp[5010][5010];

int main() {

    int n,m,x;
    cin >> n >> m >> x;

    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    for (int i = 0; i < 5010; ++i)
        for (int j = 0; j < 5010; ++j)
            dp[i][j] = -1e18;

    dp[0][0] = 0;
	for(int j = 1; j <= x; j++) {
		for(int i = 1; i <= n; i++) {
			for(int k = max(i - m, 0); k < i; k++) {
				dp[i][j] = max(dp[i][j], dp[k][j - 1] + v[i]);
			}
		}
	}

	long long ans = -1e18;
	for(int i = n - m + 1; i <= n; i++) 
        ans = max(ans, dp[i][x]);

	if(ans >= 0) cout << ans << "\n";
	else cout << "-1\n";
    

    return 0;
}

