#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long n;
    int k;
    cin >> n >> k;

    int ini = n;

    auto g = [&] (long long x) {
        string dx = to_string(x);
        string dy = dx;
        sort(dx.begin(), dx.end());
        sort(dy.rbegin(), dy.rend());
        long long a = 0;
        long long b = 0;

        for (auto c: dx) 
            a = a * 10 + (int)(c - '0');

        for (auto c: dy) 
            b = b * 10 + (int)(c - '0');
        return make_pair(a,b);
    };

    for (int i = 0; i < k and ini != 0; ++i) {
        auto [g1,g2] = g(ini);
        ini = (g2 - g1);
        
    }


        cout << ini << "\n";

    return 0;
}

