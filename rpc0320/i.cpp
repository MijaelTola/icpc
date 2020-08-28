#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n);

    for (int &x: v)
        cin >> x;

    sort(v.begin(), v.end());

    bool flag = 1;

    for (int i = 0; i < n; ++i)
        flag &= v[i] <= (i + 1);

    if(!flag) return cout << "impossible\n", 0;
    
    double mn = 1e9;

    for (int i = 0; i < n; ++i) {
        mn = min(mn, 1. * v[i] / (i + 1));
    }
    cout << mn << "\n";
    return 0;
}
