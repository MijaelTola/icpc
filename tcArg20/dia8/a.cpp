#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<long long> v(n);

    for (long long &x: v)
        cin >> x;

    for (int i = 1; i < (int)v.size(); ++i)
        v[i] += v[i - 1];


    int m;
    cin >> m;
    while(m--) {
        long long x;
        cin >> x;
        int pos = lower_bound(v.begin(), v.end(), x) - v.begin();
        cout << pos + 1 << "\n";
    }
    return 0;
}

