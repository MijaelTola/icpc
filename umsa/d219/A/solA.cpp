#include <bits/stdc++.h>

using namespace std;

int main() {
        
    int t;
    cin >> t;

    while(t--) {
        int n,m;
        cin >> n >> m;
        assert((n * m) % 2 == 0);
        cout << n * m + (n * m) / 2 << "\n";
    }
    return 0;
}

