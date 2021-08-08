#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long 
int main() {
    int n,q;
    cin >> n >> q;

    vector<ull> v(n);

    for (auto &x: v)
        cin >> x;

    auto cnt = [&] (ull dk) {
        int pos = lower_bound(v.begin(), v.end(), dk) - v.begin();
        return dk - pos;
    };
    
    while(q--) {
        ull k;
        cin >> k;
        ull a = 0, b = 4e18;
        while(b - a > 1) {
            ull mid = (a + b) / 2;
            if(cnt(mid) > k) b = mid;
            else a = mid;
        }

        cout << a << "\n";
    }
    return 0;
}

