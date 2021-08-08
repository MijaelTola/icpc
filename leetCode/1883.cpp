#include <bits/stdc++.h>

using namespace std;

long double dp[1010][1010];
int minSkips(vector<int>& dist, int speed, int hoursBefore) {

    int n = dist.size();
    
    for (int i = n; i >= 0; i--) {
        for (int j = 1009; j >= 0; j--) {
            long double &ans = dp[i][j];
            if(i == n) {
                if(j == 0) 
                    ans = 0.;
                else ans = 1e9; 
                continue;
            }
            ans = 1e9;
            
            if(i + 1 < n) {
                ans = min(ans, ceil(1. * dp[i + 1][j] + (1. * dist[i] / speed)));
            } else {
                ans = min(ans, 1. * dp[i + 1][j] + (1. * dist[i] / speed));
            }

            if(j) 
                ans = min(ans, 1. * dp[i + 1][j - 1] + 1. * (dist[i] / speed));
        }
    }

    cout << dp[0][0] << " ASDF\n";

    for (int i = 0; i < 1010; ++i) {
        if(dp[0][i] <= hoursBefore) return i;
    }

    return -1;
}

int main() {

    vector<int> v = {7,3,5,5};

    cout << minSkips(v, 2, 10) << "\n";

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            cout << dp[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

