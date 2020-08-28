#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int pl = 0, cl = 0, flag = 1;

        for (int i = 0; i < n; ++i) {
            int p,l;
            cin >> p >> l;
            if(p < pl or l < cl)  {
                flag = 0;
            }

            int dp = p - pl;
            int dc = l - cl;
            flag &= dp >= dc;
            pl = p, cl = l;
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

