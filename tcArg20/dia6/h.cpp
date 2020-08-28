#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    cin >> s;

    string p = "hello";

    int pos = 0;

    for (auto x: s) {
        if(x == p[pos]) pos++;
    }

    if(pos == (int)p.size()) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

