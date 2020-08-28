#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;
    
    bool f = 1, f2 =1;

    for (int i = 0; i < (int)s.size(); ++i) {
        if((i + 1) & 1) f &= s[i] == 'R' or s[i] == 'U' or s[i] == 'D';
        else f2 &= (s[i] == 'L' or s[i] == 'U' or s[i] == 'D');
    }
    
    if(f and f2) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

