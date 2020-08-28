#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;

    int l = 0, r = s.size() - 1;
    int ans = 0;
    while(l < r) {
        if(s[l] != s[r]) ans++;
        l++,r--;
    }
    cout << ans << "\n";
    return 0;
}

