#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,m;
    cin >> n >> m; 

    vector<int> v(n * m);

    int mn = 1e9;

    for (int &x: v) {
        cin >> x;
        mn = min(x, mn);
    }

    int ans = 0;

    for (int x: v)
        ans += abs(x - mn);

    cout << ans << endl;

    return 0;
}

