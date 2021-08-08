#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;

    bool flag = 1;

    for (int i = 0; i < (int)s.size(); ++i) {
        if(i & 1) {
            flag &= 'A' <= s[i] and s[i] <= 'Z';
        } else 
            flag &= 'a' <= s[i] and s[i] <= 'z';
    }

    if(flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

