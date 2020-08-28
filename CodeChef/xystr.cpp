#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        
        int ans = 0;
        int p = 0;

        while(p < (int)s.size() - 1) {
            ans += s[p] != s[p + 1];
            if(s[p] != s[p + 1]) p += 2;
            else p++;
        }
        cout << ans << "\n";
    }

    return 0;
}

