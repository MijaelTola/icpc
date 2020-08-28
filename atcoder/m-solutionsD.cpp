#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<long long> v(n);

    for (auto &x: v)
        cin >> x;

    long long val = 1000;
    long long cur = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (v[i] < v[i + 1]) {
            cur = val / v[i];
            val %= v[i];
            val += cur * v[i + 1];
        }
    }

    cout << val << "\n";

    return 0;
}

