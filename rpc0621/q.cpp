#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;

    int dv = s.size() / 3;
    
    
    for (int i = 0; i < dv; ++i) {
        int uno = i;
        int dos = i + dv;
        int tres = i + 2 * dv;
        auto a = s[uno];
        auto b = s[dos];
        auto c = s[tres];
        if(a == b and b == c)cout << a;
        else if(a == b) cout << a;
        else if(a == c) cout << a;
        else if(b == c) cout << b;
    }
    cout << "\n";
    return 0;
}

