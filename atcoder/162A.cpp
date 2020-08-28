#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;
    int flag = 0;

    for (auto x: s)
        flag |= x == '7';

    if(flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

