#include <iostream>
#include <algorithm>
#include <cstring> 

using namespace std;

int v[30];
int n;
int total = 300 * 60;
int dp[20][20000];
int f(int pos, int time) {
    if(time > total) return -1e9;
    if(pos == n) {
        if(time <= total) return 0;
        return -1e9;
    }

    int &ans = dp[pos][time];
    if(ans != -1) return ans;
    ans = -1e9;
    ans = max(ans, f(pos + 1, time + v[pos]) + 1);
    ans = max(ans, f(pos + 1, time));
    return ans;
}
int main() {
    memset(dp, -1,sizeof dp);
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);
    printf("%d\n", f(0,0));
    return 0;
}

