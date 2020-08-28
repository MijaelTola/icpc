#include <bits/stdc++.h>

using namespace std;

int n;
char s[1000100], c;
long long dp[1000100][2][2];

long long f(int pos, bool start, bool flag) {
    if(pos == n) return flag;
    long long &ans = dp[pos][start][flag];
    if(ans != -1) return ans;
    ans = 0;
    if(!start)  ans += f(pos + 1, start, flag);
    ans += f(pos + 1, 1, flag | (s[pos] == c));
    if(pos + 1 < n)ans += f(n, 1, flag | (s[pos] == c));
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %s %c", &n, s, &c);
        for (int i = 0; i < n; ++i) 
            dp[i][0][1] = dp[i][1][1] = dp[i][1][0] = dp[i][0][0] = -1;
        printf("%lld\n", f(0, 0, 0));
    }
    return 0;
}

