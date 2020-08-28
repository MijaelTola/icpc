#include <bits/stdc++.h>

using namespace std;

long long n,w;
long long a[1010];

int main() {
    
    cin >> n >> w;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    long long ini = 0;
    vector<long long> down, up;

    for (int i = 0; i < n; ++i) {
        ini += a[i];
        down.push_back(ini);
    }
    
    ini = w;

    for (int i = 0; i < n; ++i) {
        ini += a[i];
        up.push_back(ini);
    }
    
    long long mn = LLONG_MAX;
    long long mx = -LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        mn = min(mn, down[i]);
        mx = max(mx, up[i]);
    }
    
    if(mn < 0) mn = abs(mn);
    else mn = 0;

    if(mx > w) mx = w - (mx - w);
    else mx = w;
    
    cout << max(0ll,mx - mn + 1) << "\n";

    return 0;
}

