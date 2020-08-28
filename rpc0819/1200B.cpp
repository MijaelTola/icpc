#include <bits/stdc++.h>

using namespace std;

int v[110];
long long n,m,k;

int main() {

    int t;
    cin >> t;
    while(t--) {
        memset(v, 0,sizeof v);
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        
        bool flag = 1;
        for (int i = 0; i < n - 1; ++i) {
            int d = (v[i] + k) - v[i + 1];
            if(d < 0) {
                if(m >= -d) m += d;
                else {
                    flag = 0;
                    break;
                }
            } else m += min(v[i], d);
        }
        if(flag) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}

