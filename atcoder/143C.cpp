#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    string s;
    cin >> n >> s;
    
    char last = '#';
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] != last) ans++;
        last = s[i];
    }
    cout << ans << "\n";
    return 0;
}

