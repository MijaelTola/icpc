#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int a = 0, b = 0;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(x & 1) a++;
            else b++;
        }

        if(a & 1) cout << "YES\n";
        else if(a and b) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

