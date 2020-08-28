#include <bits/stdc++.h>

using namespace std;

int main() {

    long long n,k;
    cin >> n >> k;

    long long a = -1, b = k + 1;

    auto get = [&] (long long x) {
        return x * (x + 1) / 2;
    };

    auto ver = [&] (long long dk) {
        long long l = k - dk;
        long long total = get(k) - get(l) - (dk - 1);
        return total >= n;
    };

    while(b - a > 1) {
        long long mid = (a + b) / 2;
        if(ver(mid)) b = mid;
        else a = mid;
    }

    if(b == k + 1) cout << "-1\n";
    else cout << b << "\n";
    return 0;
}

