#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        vector<int> l(s.size()), r(s.size());
        
        int a,b;
        cin >> a >> b;
        
        bool flag = 0;

        int n = s.size();
        
        int cur = 0;

        for (int i = 0; i < n; ++i) {
            int x = s[i] - '0';
            cur = cur * 10 + x;
            cur %= a;
            l[i] = cur;
        }

        cur = 0;
        int p = 1;

        for (int i = n - 1; i >= 0; i--) {
            int x = s[i] - '0';
            cur = x * p + cur;
            cur %= b;
            r[i] = cur;
            p = (10 * p) % b;
        }
        
        for (int i = 0; i < n - 1; ++i) {
            if(s[i + 1] != '0') {
                flag |= l[i] == 0 and r[i + 1] == 0;
            }
        }
    
        if(flag) cout << "SI\n";
        else cout << "NO\n";
    }

    return 0;
}

