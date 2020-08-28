#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    string s;
    cin >> n >> s;

    set<int> r,w;
    
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'R') r.insert(i);
        else w.insert(i);
    }

    int ans = 0;
    while(w.size() > 0 and r.size() > 0 and *w.begin() < *r.rbegin()) {
        ans++;
        int x = *w.begin();
        int y = *r.rbegin();
        w.erase(x);
        r.erase(y);
        w.insert(y);
        r.insert(x);
    }

    cout << ans << "\n";
    return 0;
}

