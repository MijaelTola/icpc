#include <bits/stdc++.h>

using namespace std;

long long v[1000010];

int main() {
    
    int n,k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    auto ver = [&] (long long dk) {
        long long cur = 0;
        for (int i = 0; i < n; ++i) {
            if(v[i] > dk) cur += v[i] / dk;
        }
        return cur <= k;
    };

    long long a = 0, b = 1e10;

    while(b - a > 1) {
        long long mid = (a + b) / 2;
        if(ver(mid)) b = mid;
        else a = mid;
    }

    cout << b << "\n";
    return 0;
}

