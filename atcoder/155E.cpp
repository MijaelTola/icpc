#include <bits/stdc++.h>

using namespace std;

int dp[200010];
string s;

int main() {
    
    cin >> s;
    

    auto f = [] () {
        for (int i = 0; i < 200000; ++i) dp[i] = 1e9;
        dp[s.size()] = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = s[i] - '0'; j <= 9; ++j) {
                int val = s[i] - '0';
                dp[i] = min(dp[i], dp[i + 1] + j + (j - val));

            }
        }
        return dp[0];
    };
    
    int a1 = f();

    s = "1" + s;

    int a2 = f();
    cout << a1 << " " << a2 << "\n";
    return 0;
}

