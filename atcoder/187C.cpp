#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<string> v(n);
    set<string> s;

    for (auto &x: v) {
        cin >> x;
        s.insert(x);
    }

    for (int i = 0; i < n; ++i) {
        if(v[i][0] == '!') {
            string t = v[i].substr(1);
            if(s.count(t))
                return cout << t << "\n", 0;
        }
    }

    cout << "satisfiable" << "\n";


    return 0;
}

