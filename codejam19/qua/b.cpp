#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        int n;
        string s;
        cin >> n >> s;
        cout << "Case #" << i << ": ";
        for (char x: s)
            if(x == 'S') cout << "E";
            else cout << "S";
        cout << "\n";
    }
    return 0;
}

