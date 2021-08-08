#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int>s;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }

    if((int)s.size() == n) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}

