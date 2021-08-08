#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x: v)
        cin >> x;

    set<int> s;
    for (int i = 0; i <= 200000; ++i)
        s.insert(i);

    for (int i = 0; i < n; ++i) {
        s.erase(v[i]);
        cout << *s.begin() << "\n";
    }

    return 0;
}

