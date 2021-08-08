#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n + 1; ++i) {
        string s;
        cin >> s;
        string ds = s.substr(s.size() - 2, s.size() - 1);
        int x = stoi(ds);
        v.push_back(x);
    }

    int ini = v[0];

    int ans = 0;
    for (int i = 1; i < n + 1; ++i) {
        ini += v[i];
        ans += (ini % 100 != 0);
    }

    cout << ans << "\n";
    return 0;
}

