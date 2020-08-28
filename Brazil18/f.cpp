#include <bits/stdc++.h>

using namespace std;
int n;

vector<pair< pair<int,int>, pair<int,int> > > v;
vector<pair< pair<int,int>, pair<int,int> > > b;
int dp[2000][1100];
int bs(int i, int x) {
    int a = i;
    int b = v.size();
    while(b - a > 1) {
        int mid = (a + b) / 2;
        int ini = v[mid].first.first;
        if(ini >= x) b = mid;
        else a = mid;
    }
    return b;
}

int f(int pos, int mask) {
    if(pos == (int)b.size()) {
        if(__builtin_popcount(mask) == n) return 0;
        return -1e9;
    }
    int &ans = dp[pos][mask];
    if(ans != -1) return ans;
    ans = -1e9;
    int next = b[pos].first.second;
    int val = b[pos].second.first;
    int mk = b[pos].second.second;
    ans = max(ans,f(pos + 1, mask));
    ans = max(ans,f(next, mask | (1 << mk)) + val);
    return ans;
}
int main()  {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        for (int j = 0; j < m; ++j) {
            int ini,fin,val;
            cin >> ini >> fin >> val;
            v.push_back({{ini,fin},{val,i}});
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < (int)v.size(); ++i) {
        int ini = v[i].first.first;
        int fin = v[i].first.second;
        int val = v[i].second.first;
        int mask = v[i].second.second;
        int next = bs(i,fin);
        b.push_back({{ini,next},{val,mask}});
    }
    if(f(0,0) < 0) cout << "-1\n";
    else cout << f(0,0) << "\n";
    return 0;
}
