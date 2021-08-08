#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;

    cin >> s;

    for (auto c: s)
        if(c == '.') break;
        else cout<< c;
    cout << "\n";

    return 0;
}

