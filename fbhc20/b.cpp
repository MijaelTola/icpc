#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    int k = 1;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            if(s[i] == 'A')a++;
            else b++;
        }
        cout << "Case #" << k++ << ": ";
        if(abs(a - b) <= 1) cout << "Y\n";
        else cout << "N\n";

    }
    return 0;
}

