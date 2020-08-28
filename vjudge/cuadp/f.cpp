#include <bits/stdc++.h>

using namespace std;

int a[100010];
int b[100010];

int main() {
    
    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        if ('A' <= s[i] and s[i] <= 'Z') a[i] = 1;
        else b[i] = 1;
    }
    
    for (int i = 0; i < n; ++i) 
        b[i] += b[i - 1];
    
    for (int i = n - 1; i >= 0; --i)
        a[i] += a[i + 1];

    int ans = min(b[n - 1], a[0]);

    for (int i = 0; i < n; ++i) {
        ans = min(ans, b[i] + a[i + 1]);
    }

    cout << ans << "\n";
    
    return 0;
}

