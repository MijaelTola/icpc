#include <iostream>
#include <cstring>
#include <cstdio> 
#include <algorithm>

using namespace std;

int n;
int p[110];
int t[110];
int dp[110][2][2];
int f(int pos, bool pp, bool tt) {
    if(pos == n) {
        if(pp && tt) return 0;
        return -1e9;
    }
    int &ans = dp[pos][pp][tt];
    if(ans != -1) return ans;
    ans = -1e9;
    ans = max(ans, f(pos + 1, 1, tt) + p[pos]);
    ans = max(ans, f(pos + 1, pp, 1) + t[pos]);
    return ans;
}
int main() {
#ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", p + i);
    
    for (int i = 0; i < n; ++i)
        scanf("%d", t + i);

    printf("%d\n", f(0,0,0));
    return 0;
}

