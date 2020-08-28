#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int ans = 0;
        for (char x: s)
            ans += x == '1';
        if(ans & 1) cout << "WIN\n";
        else cout << "LOSE\n";
        
    }
    return 0;
}

