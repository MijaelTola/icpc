#include <bits/stdc++.h>

using namespace std;

int dp[5010][5010];
int main() {
    
    string s;
    cin >> s;


    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = 0; j < 3; ++j) {
            int &ans = dp[i][j] = 0;
            if(j == 0) {
                ans = max(ans, dp[i + 1][j] + (s[i] == 'a'));
                ans = max(ans, dp[i + 1][1] + (s[i] == 'b'));
            }
            if(j == 1) {
                ans = max(ans, dp[i + 1][j] + (s[i] == 'b'));
                ans = max(ans, dp[i + 1][2] + (s[i] == 'a'));
            } 
            if(j == 2) 
                ans = max(ans, dp[i + 1][j] + (s[i] == 'a'));

        }
    }

    cout << dp[0][0] << "\n";
    return 0;
}

