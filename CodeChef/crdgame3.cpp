#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int c,r;
        cin >> c >> r;
        
        int a = c / 9;
        a += c % 9 != 0;

        int b = r / 9;
        b += r % 9 != 0;

        if(a < b) 
            cout << "0 " << a << "\n";
        else 
            cout << "1 " << b << "\n";
    }
    return 0;
}

