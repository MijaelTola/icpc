#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        string s;
        cin >> s;
        int a = 0, b = 0;
        for (int i = 1; i < (int)s.size(); i++) {
            a += s[i] == '.';
            b += s[i] == 'B';
        }
        cout << "Case #" << k << ": ";
        if((b >= a or b >= 2) and a) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}


