#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long n;
    cin >> n;

    set<long long> s;

    for (long long i = 2; i * i <= n; i++) {
        long long p = i * i;

        while(p <= n) {
            s.insert(p);
            p *= i;
        }
    }

    cout << n - s.size() << "\n";
    return 0;
}

