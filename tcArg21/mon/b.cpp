#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    string s;
    cin >> n >> s;
    
    string ans = s;
    for (int i = 0; i < n; ++i) {
        string ds = s;
        int df = 10 - (s[i] - '0');
        for (int j = 0; j < n; ++j) {
            int val = ds[j] - '0';
            val = (val + df) % 10;
            ds[j] = (char)(val + '0');
        }
        
        string cur = "";
        for (int j = i, c = 0; c < n; ++c, j = (j + 1) % n) {
            cur += ds[j];
        }
        
        ans = min(ans, cur);
    }
    cout << ans << "\n";
    return 0;
}

