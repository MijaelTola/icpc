#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        long long a,b;
        cin >> a >> b;
    
        a = sqrt(a - 1), b = sqrt(b);
        cout << b - a << "\n";
    }
    return 0;
}

