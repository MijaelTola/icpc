#include <bits/stdc++.h>

using namespace std;

int n,m;
string s,t;
vector<int> a[260];

int main() {
    
    cin >> s >> t;
    
    for (int i = 0; i < (int)s.size(); ++i)
        a[int(s[i])].push_back(i);


    int ini = -1;
    long long cnt = 0;
    for (int i = 0; i < (int)t.size(); ++i) {
        bool flag = 0;
        again:
        int pos = upper_bound(a[(int)t[i]].begin(), a[(int)t[i]].end(), ini) - a[(int)t[i]].begin();
        if(pos == (int)a[(int)t[i]].size()) {
            if(flag) return puts("-1"), 0;
            cnt++;
            ini = -1;
            flag = 1;
            goto again;
        } else ini = a[(int)t[i]][pos];
    }
    
    long long ans = (long long)s.size() * cnt + ini + 1;
    cout << ans << "\n";
    
    return 0;
}

