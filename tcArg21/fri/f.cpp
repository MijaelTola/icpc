#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m;
    cin >> n >> m;

    vector<int> v(n);

    for (auto &x: v)
        cin >> x;

    sort(v.begin(), v.end());

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        int p = upper_bound(v.begin(), v.end(), x) - v.begin();
        cout << p << " ";
    }
    cout << "\n";
    return 0;
}

