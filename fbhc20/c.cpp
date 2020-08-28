#include <bits/stdc++.h>

using namespace std;

long long dp[8000010][2];
vector<pair<int,int> > v;
map<long long, vector<int> > mp, no;
int k = 1;
long long f(int pos, int flag) {

    long long ans = dp[pos][flag];
    //if(ans != -1) return ans;
    ans = 0;

    long long p = v[pos].first;
    long long h = v[pos].second;
    if(flag == 1) {
        ans = h;
        for (auto pp: no[p + h]) {
            ans = max(ans, f(pp, 1) + h);
        }

        for (auto pp: mp[p + h]) {
            int uh = v[pp].second;
            ans = max(ans, f(pp, 0) + uh + h);
        }
    } else {
        for (auto pp: mp[p]) {
            int uh = v[pp].second;
            ans = max(ans, f(pp, 0) + uh);
        }
    }


    return ans;
}

int main() {

    int t;
    scanf("%d\n", &t);

    while(t--) {
        v.clear();
        no.clear();
        mp.clear();
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            dp[i][0] = dp[i][1] = 0;
            int p,h;
            scanf("%d %d", &p, &h);
            mp[p - h].push_back(i);
            no[p].push_back(i);
            v.push_back({p,h});
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 2; ++j) {
                long long &ans = dp[i][j];
                long long p = v[i].first;
                long long h = v[i].second;
                if(j == 1) {
                    ans = h;
                    for (auto pp: no[p + h]) {
                        ans = max(ans, dp[pp][1] + h);
                    }

                    for (auto pp: mp[p + h]) {
                        int uh = v[pp].second;
                        ans = max(ans, dp[pp][0] + uh + h);
                    }

                } else {
                    for (auto pp: mp[p]) {
                        int uh = v[pp].second;
                        ans = max(ans, dp[pp][0] + uh);
                    }
                }
            }
        }

        long long res = 0;

        for (int i = 0; i < n; ++i) {
            res = max({res, dp[i][0], dp[i][1]});
        }
        //cout << res << "\n";
        printf("Case #%d: %lld\n", k++, res);

    }
    return 0;
}

