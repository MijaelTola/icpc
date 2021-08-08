#include <bits/stdc++.h>

using namespace std;

int a,b,w;

int main() {

    cin >> a >> b >> w;

    w *= 1000;

    int mn = 1e9;
    int mx = 0;

    for (int i = a; i <= b; ++i) {
        mn = min(w / i, mn);
        mx = max(w / i, mx);
    }

    if(mn == 1e9) cout << "UNSATISFIABLE\n";
    else cout << mn << " " << mx << "\n";
    return 0;
}

