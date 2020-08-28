#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[15010];
int b[15010];
int pa[15010];
int pb[15010];
int dp[15010][3];
int dep[15010];

int main() {
    cin >> n >> m;
    
    map<int,int> last;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pa[i] = last[a[i]];
        last[a[i]] = i;
    }
    last.clear();
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        pb[i] = last[b[i]];
        last[b[i]] = i;
    }
        
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(i) dp[i][1] = max(dp[i][1], dp[i - 1][1]);
            if(j) dp[i][1] = max(dp[i][1], dp[j][0]);
            if(a[i] == b[j]) 
                dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
        }
        swap(dp[0], dp[1]);
    }
    cout << dp[n - 1][0] << "\n";
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(a[i] == b[j] and pa[i] != i and pb[j] != j) 
                dp[i][j] = max(dp[i][j], dp[pa[i]][pb[j]] + 1);
            if(i) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if(j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
    }
    
   
    cout << 2 * dp[n - 1][m - 1] << "\n";*/
    return 0;
}

