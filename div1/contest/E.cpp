#include <bits/stdc++.h>

using namespace std;

int v[20][20],dp[20][65540],n;

bool ver(int newmask, int mask) {
    for (int i = 0; i < n - 1; ++i) {
        bool a = newmask & (1 << i);
        bool b = newmask & (1 << (i + 1));
        if(a == b and a and b) return 0;
    }
    for (int i = 0; i < n; ++i) {
        if(newmask & (1 << i)) {
            bool a = mask & (1 << (i - 1));
            bool b = mask & (1 << i);
            bool c = mask & (1 << (i + 1));
            if(!a and !b and !c)continue;
            else return 0;
        } 
    }
    return 1;
}

int f(int x, int mask) {
    if(x == n) return 0;
    if(dp[x][mask] != -1) return dp[x][mask];
    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        if(ver(i, mask)) {
            int sum = 0;
            for (int j = 0; j < n; ++j) 
                if(i & (1 << j)) sum += v[x][j];
            ans = max(ans,f(x + 1, i) + sum);
        }
    }
    ans = max(ans,f(x + 1, 0));
    return dp[x][mask] = ans;
}

int main(){
    int t; 
    scanf("%d", &t);
    while(t--) {
        memset(dp, -1, sizeof dp);
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> v[i][j];

        printf("%d\n", f(0,0));
    }
    return 0;
}

