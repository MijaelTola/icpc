#include <bits/stdc++.h>

using namespace std;

int main() {

    long long n;
    cin >> n;

    auto get = [&]( long long z) {
        return z * (z - 3) / 2;
    };
    
    for (long long i = 1; i < 100000000; ++i) {
        if(get(i) + i == n) return cout << i << "\n", 0;
    }
    return 0;
}

