#include <bits/stdc++.h>

using namespace std;

int a[27];
bool b[27];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        memset(a, 0,sizeof a);
        int n;
        cin >> n;
        int dn = n;
        while(n--) {
            memset(b, 0, sizeof b);
            string s;
            cin >> s;
            for (char x: s) b[x - 'a'] = 1;
            for (int i = 0; i < 27; ++i)
                a[i] += b[i];
        }
        int ans = 0;
        for (int i = 0; i < 27; ++i) 
            ans += a[i] == dn;
        
        cout << ans << "\n";
    }
    return 0;
}

