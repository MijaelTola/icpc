#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    string s;
    cin >> n >> s;
    
    vector<int> v[3];

    for (int i = 0; i < n; ++i) {
        if(s[i] == 'R') v[0].push_back(i);   
        if(s[i] == 'G') v[1].push_back(i);   
        if(s[i] == 'B') v[2].push_back(i);   
    }
    
    auto check = [&] (vector<int> a, vector<int> b, vector<int> c) {
        long long aa = 0;
        for (int l: a) {
            for (int m: b) {
                if(m < l) continue;
                int d = m - l;
                int pos = upper_bound(c.begin(), c.end(), m) - c.begin();
                int cur = lower_bound(c.begin(), c.end(), m + d) - c.begin();
                aa += c.size() - pos;
                if(cur < (int)c.size() and c[cur] == m + d) aa--;
            }
        }
        return aa;
    };

    
    long long ans = 0;
    vector<int> bb = {0,1,2};
    do {
        ans += check(v[bb[0]], v[bb[1]], v[bb[2]]);
    } while(next_permutation(bb.begin(), bb.end()));

    cout << ans << "\n";

    return 0;
}

