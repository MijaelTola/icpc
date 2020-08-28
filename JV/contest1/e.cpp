#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    while(cin >> n) {
        int x,y,z;
        x = y = z = 0;
        while(n--) {
            int a,b,c;
            cin >> a >> b >> c;
            x += a;
            y += b;
            z += c;
        }

        if(!x and !y and !z) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;

}

