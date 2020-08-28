#include <bits/stdc++.h>

using namespace std;

int n,m,x;
int dp[7][65][65][65];

bool mined(int c, int r, int last, int mid, int next) {
    bool flag = 0;
    if(c - 1 >= 0) {
        if(r - 1 >= 0) flag |= !(last & (1 << (r - 1)));
        if(r + 1 < n) flag |= !(last &(1 << (r + 1)));
        flag |= !(last & (1 << r));
    }
    
    if(c + 1 < m) {
        if(r - 1 >= 0) flag |= !(next & (1 << (r - 1)));
        if(r + 1 < n) flag |= !(next &(1 << (r + 1)));
        flag |= !(next & (1 << r));
    }

    if(r - 1 >= 0) flag |= !(mid & (1 << (r - 1)));
    if(r + 1 < n) flag |= !(mid & (1 << (r + 1)));

    return flag;
}

bool empty(int c, int r, int last, int mid, int next) {
    int cnt = 0;
    if(c - 1 >= 0) {
        if(r - 1 >= 0) cnt += (last & (1 << (r - 1))) != 0 ? 1 : 0;
        if(r + 1 < n) cnt += (last & (1 << (r + 1))) != 0 ? 1 : 0;
        cnt += (last & (1 << r)) != 0 ? 1 : 0;
    }
    if(c + 1 < m) {
        if(r - 1 >= 0) cnt += (next & (1 << (r - 1))) != 0 ? 1 : 0;
        if(r + 1 < n) cnt += (next & (1 << (r + 1))) != 0 ? 1 : 0;
        cnt += (next & (1 << r)) != 0 ? 1 : 0;
    }

    if(r - 1 >= 0) cnt += (mid & (1 << (r - 1))) != 0 ? 1 : 0;
    if(r + 1 < n) cnt += (mid & (1 << (r + 1))) != 0 ? 1 : 0;
    return cnt <= x;
}

bool ver(int c,int r, int last, int mid, int next) {
    bool turn = mid & (1 << r);
    if(turn) return mined(c, r, last, mid, next);
    else return empty(c, r, last, mid, next);
}

int f(int pos, int l2, int l1, int actual) {
    if(pos == m) return 0;
    
    int &ans = dp[pos][l2][l1][actual];
    //if(ans != -1) return ans;
    ans = 0;
    ans = max(ans, f(pos + 1, l1, actual, 0));
    for (int i = 0; i < n; ++i) {
        if(actual & (1 << i)) continue;
        int cur = actual | (1 << i);
        bool flag = 1;
        flag &= ver(pos - 1, i - 1, l2, l1, cur);
        flag &= ver(pos - 1, i, l2, l1, cur);
        flag &= ver(pos - 1, i + 1, l2, l1, cur);
        flag &= ver(pos, i - 1, l1, cur, 0);
        flag &= ver(pos, i, l1, cur, 0);
        flag &= ver(pos, i + 1, l1, cur, 0);
        flag &= ver(pos + 1, i - 1, cur, 0, 0);
        flag &= ver(pos + 1, i, cur, 0, 0);
        flag &= ver(pos + 1, i + 1, cur, 0, 0);

        if(flag) {
            ans = max(ans, f(pos + 1, l1, cur, 0) + 1);
            ans = max(ans, f(pos, l2, l1, cur) + 1);
        }
    }
    return ans;
}

int main() {
    int t; 
    scanf("%d", &t);
    while(t--) {
        memset(dp, -1, sizeof dp);
        scanf("%d%d%d",&n, &m, &x);
        printf("%d\n",f(0,0,0,0));
    }
    return 0;
}
