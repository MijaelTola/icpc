#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long x,y,z;

    cin >> x >> y >> z;

    auto get = [x, y] (long long cur) {
        long long c = log10(cur) + 1;
        return x * cur + y * c;
    };

    int a = 0, b = 1e9 + 1;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(get(mid) > z) b = mid;
        else a = mid;
    }
    b--;
    cout << b << "\n";
    return 0;
}

