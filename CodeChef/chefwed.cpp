#include <bits/stdc++.h>

using namespace std;


int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        
        int n,k;
        cin >> n >> k;
        vector<int> v(n);
        vector<long long> dp(n + 10, 0);

        for (int &x: v)
            cin >> x;

        for (int i = n - 1; i >= 0; i--) {
            int cost = 0;
            unordered_map<int,int> mp;
            dp[i] = 1e12;
            for (int j = i; j < n; ++j) {
                mp[v[j]]++;
                if(mp[v[j]] == 2) {
                    cost += 2;
                }
                if(mp[v[j]] > 2)
                    cost ++;
                
                dp[i] = min(dp[i], dp[j + 1] + cost + k);
            }
        }

        cout << dp[0] << "\n";
    }
    return 0;
}

