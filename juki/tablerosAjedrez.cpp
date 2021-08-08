#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    int f[30];

    f[1] = 1, f[2] = 2;

    for (int i = 3; i < 30; ++i)
        f[i] = f[i - 1] + f[i - 2];

    while(t--) {
    
        int x;
        cin >> x;
        cout << f[x] << "\n";
    }
    return 0;
}

