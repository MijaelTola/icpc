#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    while(cin >> n) { 
        bool ans = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            ans |= x;
        }

        if(ans) cout << "HARD\n";
        else cout << "EASY\n";
    }

    return 0;
}
