#include <bits/stdc++.h>

using namespace std;

int n;
int v[100010];
int dp[100010][4][4];

int f(int pos, int cur, int flag) {
    if(pos == n + 1) return 0;

    int &ans = dp[pos][cur][flag];
    if(ans != -1) return ans;
    ans = 0;


    if(cur == 0) {
        ans = max(ans, f(pos + 1, cur, flag));
        ans = max(ans, f(pos + 1, cur + 1, flag) + (pos > 0)); 
        ans = max(ans, f(pos + 1, cur + 1, 2) + (pos > 0)); 
    } 

    if(cur == 1) {
        if(v[pos] > v[pos - 1] or flag == 2) {
            if(flag != 2) ans = max(ans, f(pos + 1, cur, flag) + 1);
            else ans = max(ans, f(pos + 1, cur, 3) + 1);

            if(v[pos + 1] - v[pos - 1] > 1 and flag == 0) {
                ans = max(ans, f(pos + 1, cur, 2) + 1);
            }

        } else if(flag == 0) {
            if(v[pos + 1] - v[pos - 1] > 1) {
                ans = max(ans, f(pos + 1, cur, 2) + 1);
            }
            ans = max(ans, f(pos + 1, cur + 1, 2) + 1);
        } 
    }

    if(cur == 2)
        ans = max(ans, f(pos + 1, cur, flag));

    return ans;
}
int main() {
    
    memset(dp, -1, sizeof dp);
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    v[0] = -1e9 + 7;
    v[n + 1] = 1e9 + 7;
    cout << f(1,0,0) << "\n";
    return 0;
}
