#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<string> v;
unordered_map<string,vector<string> > cmp, imp;

long long dp[25][3];
long long f(int pos, bool is) {
    if(pos == n) return is == 0;
    long long &ans = dp[pos][is];
    if(ans != -1) return ans;
    ans = 0;
    ans += f(pos + 1, is) * cmp[v[pos]].size();
    ans += f(pos + 1, 0) * imp[v[pos]].size();
    return ans;
}

void r(int pos, bool is) {
    if(pos == n) return;
    if(f(pos + 1, is) == 1) {
        if(cmp[v[pos]].size()) cout << cmp[v[pos]][0];
        else cout << imp[v[pos]][0];
        if(pos + 1 < n) cout << " ";
        r(pos + 1, is);   
        return;

    }
    if(f(pos + 1, 0) == 1) {
        if(cmp[v[pos]].size()) cout << cmp[v[pos]][0];
        else cout << imp[v[pos]][0];
        if(pos + 1 < n) cout << " ";
        r(pos + 1, 0);   
        return;
    }
}

int main() {
    while(cin >> n) {
        memset(dp, -1, sizeof dp);
        v.clear();
        imp.clear();
        cmp.clear();
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            v.push_back(s);
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            string x,y,z;
            cin >> x >> y >> z;
            if(z == "correct") {
                cmp[x].push_back(y);
            }
            else imp[x].push_back(y);
        }
        long long ans1 = 1;
        for (int i = 0; i < n; ++i) {
            ans1 *= cmp[v[i]].size();
        }

        long long ans2 = f(0,1);
        if(ans1 == 1 and !ans2) {
            for (int i = 0; i < n; ++i) {
                cout << cmp[v[i]][0];
                if(i + 1 < n) cout << " ";
            }
            cout << "\ncorrect\n";
            continue;
        }

        if(!ans1 and ans2 == 1) {
            r(0,1);
            cout << "\nincorrect\n";
            continue;
        }

        cout << ans1 << " correct\n";
        cout << ans2 << " incorrect\n";
    }
    return 0;
}

