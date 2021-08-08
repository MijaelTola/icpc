#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> v, ac;
int dp[4003][8003];

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &n, &k);

        v.clear();
        ac.clear();

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            x = min(x, k);
            v.push_back(x);
            ac.push_back(x);
        }

        sort(v.rbegin(), v.rend());
        sort(ac.rbegin(), ac.rend());

        for (int i = 1; i < n; ++i)
            ac[i] += ac[i - 1];


        for (int pos = n; pos >= 0; pos--) {
            for (int sum = 2 * k; sum >= 0; sum--) {
                if(pos == n) {
                    int sum2 = ac[pos - 1] - sum;
                    if(sum >= k and sum2 >=k) dp[pos][sum] = 0;
                    else dp[pos][sum] = 1e9;
                    continue; 
                }

                int sum2 = ac[pos - 1] - sum;
                if(sum >= k and sum2 >= k) {
                    dp[pos][sum] = 0;
                    continue;
                }

                int &ans = dp[pos][sum] = 1e9;

                if(sum < k) 
                    ans = min(ans, dp[pos + 1][sum + v[pos]] + 1);
                ans = min(ans, dp[pos + 1][sum] + 1);
            }
        }

        if(dp[0][0] == 1e9) puts("-1");
        else printf("%d\n", dp[0][0]);


    }
    return 0;
}

