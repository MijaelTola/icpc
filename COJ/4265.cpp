#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    double x = log10(2);
    double y = log10(5);
    while(t--) {
        int a,b;
        cin >> a >> b;
        cout << (int)(x * a + y * b) + 1 << "\n";
    }
    return 0;
}

