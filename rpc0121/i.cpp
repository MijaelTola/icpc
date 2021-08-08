#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long a,b;
    while(cin >> a >> b and a and b) {
        int sign = 1;

        long long dv = b / 2;

        if(dv & 1LL) sign = -1;

        //cout << sign << " " <<  a << "\n";
        cout << sign * a;
        if(b & 1) cout << "i";
        cout << "\n";
    }
    return 0;
}
