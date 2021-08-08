#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<pair<int, string> > v;

    for (int i = 0; i < n; ++i) {
        string s;
        int t;
        cin >> s >> t;
        v.push_back({t,s});
    }

    sort(v.rbegin(), v.rend());

    cout << v[1].second << "\n";

    return 0;
}

