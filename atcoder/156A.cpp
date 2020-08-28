#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,r;
    cin >> n >> r;
    if(n >= 10) cout << r << "\n";
    else {
        int lol = 100 * (10 - n);
        cout << r + lol << "\n";
    }
    return 0;
}

