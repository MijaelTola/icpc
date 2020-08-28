#include <bits/stdc++.h>

using namespace std;

vector<int> v[20];
int cnt[20][20];
int dp[1 << 20][20];
int  n;
int mk;
int solve(int a, int b) {
    if(a == b) return 0;
    int id = -1;
    for (int i = 0; i < (int)v[a].size(); ++i) {
        bool flag = 1;
        for (int j = 0, p = i; j < (int)v[b].size() and p < (int)v[a].size(); ++j, p++) 
            flag &= (v[a][p] == v[b][j]);

        if(flag) {
            id = i;
            break;
        }
    }
    if(id == -1) return 0;
    int sz = v[a].size() - id;
    return sz;
}

void del(int a, int b) {
    if(a == b) return;
    for (int i = 0; i < (int)v[a].size(); ++i) {
        bool flag = 1;
        int cnt = 0;
        for (int j = 0, p = i; j < (int)v[b].size() and p < (int)v[a].size(); ++j, p++) {
            flag &= (v[a][p] == v[b][j]);
            cnt++;
        }

        if(flag and cnt == (int)v[b].size()) {
            mk |= (1 << b);
            return;
        }
    }

}
int f(int mask, int last) {
    if(mask == (1 << n) - 1) return 0;
    int &ans = dp[mask][last];
    if(ans != -1) return ans;
    ans = 1e9;
    for (int i = 0; i < n; ++i) 
        if(!(mask & (1 << i)) and last != i) 
            ans = min(ans, f(mask | (1 << i), i) + max((int)v[i].size() - cnt[last][i],0));
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    memset(cnt, 0, sizeof cnt);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    set<vector<int> > S; S.clear();
    for(int i = 0; i < n; i++) {
        S.insert(v[i]);
    }
    n = 0;
    for(set<vector<int> > :: iterator it = S.begin(); it != S.end(); it++) {
        v[n] = (*it);
        n++;
    }
    mk = 0;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) {
            cnt[i][j] = solve(i,j);  
            del(i,j);
        }

    cout << f(mk,17) << "\n"; 


    return 0;
}

