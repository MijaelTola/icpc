#include <bits/stdc++.h>

using namespace std;

int main() {

    string s,t;
    cin >> s >> t;

    int p = 0, pos = 0;
    
    while(p < (int)s.size() and pos < (int)t.size()) {
        if(s[p] == t[pos]) p++;
        pos++;
    }

    int l = pos - 1;

    p = s.size() - 1, pos = t.size() - 1;

    while(p >= 0 and pos >= 0) {
        if(s[p] == t[pos]) p--;
        pos--;
    }
    
    int r = pos + 1;

    int ans = 0;
    for (int i = 0; i < (int)t.size(); ++i) {
        ans += i >= l and i < r;
    }
    cout << ans << "\n";
    return 0;
}

