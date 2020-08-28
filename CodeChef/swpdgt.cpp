#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    while(t--) {
        string a,b;
        cin >> a >> b;
        
        int ans = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
            for (int j = 0; j < (int)b.size(); ++j) { 
                swap(a[i], b[j]);
                ans = max(ans, stoi(a) + stoi(b));
                swap(a[i], b[j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

