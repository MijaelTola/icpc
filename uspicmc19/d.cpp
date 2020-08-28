#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s,t;
    cin >> s >> t;

    int ds = 0, dt = 0;
    while(ds < (int)s.size() and dt < (int)t.size()) {
        if(s[ds] == t[dt]) ds++, dt++;
        else ds++;
    }

    puts(dt == (int)t.size() ? "YES" : "NO");
    return 0;
}

