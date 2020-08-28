#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    if(n & 1) {
        cout << "0\n";
        return 0;
    }
    int ans = n >> 1;
    cout << ((ans >> 1) - !(ans & 1)) << "\n";
    return 0;
}

