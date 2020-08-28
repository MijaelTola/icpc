#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    map<int,int> a,b;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        a[x] = y;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        b[x] = y;
    }

    long long ans = 0;

    for (auto p: a) 
        if(p.second >= b[p.first]) ans += p.second;

    for (auto p: b) 
        if(p.second > a[p.first]) ans += p.second;
    
    cout << ans << "\n";
    return 0;
}

