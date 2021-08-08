#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (auto &x: a)
        cin >> x;

    for (auto &x: b)
        cin >> x;

    long long ans = 0;

    for (int i = 0; i < n; ++i)
        ans += a[i] * b[i];

    if(ans == 0) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}

