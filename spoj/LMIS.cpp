#include <bits/stdc++.h>

using namespace std;

vector<int> v;
//0 1 2 3
//2 5 3 1
//
//2 4 1 -2

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int x;
    while(cin >> x) 
        v.push_back(x);

    vector<int> a(1000100, 1e9);
    a[0] = -1e9;
    int mx = 1;
    for (int i = 0; i < (int)v.size(); ++i) {
        int pos = upper_bound(a.begin(), a.end(), v[i]) - a.begin();
        a[pos] = v[i];
        mx = max(mx, pos);
    }

    cout << v.size() - mx << "\n";
    return 0;
}

