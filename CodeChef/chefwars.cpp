#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int h,p;
        cin >> h >> p;

        while(h > 0 and p > 0) {
            h -= p;
            p /= 2;
        }

        cout << (h <= 0) << "\n";
    }
    return 0;
}

