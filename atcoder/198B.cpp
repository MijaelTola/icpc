#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;
    
    auto check = [&] (string x) {
        string dx = x;
        reverse(dx.begin(), dx.end());
        return dx == x;
    };

    for (int i = 0; i < 100; ++i) {
        if(check(s)) return cout << "Yes\n", 0;
        s = "0" + s;
    }
    
    cout << "No\n";
    return 0;
}

