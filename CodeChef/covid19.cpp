#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    scanf("%d", &t);
    
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> v(n);
        for (int &x: v)
            scanf("%d", &x);
        
        int mn = 1e9;
        int mx = 1;

        for (int i = 0; i < n; ++i) {
            int cur = 1;
            int l = i - 1;
            while(l >= 0 and abs(v[l] - v[l + 1]) <=2) {
                l--,cur++;
            }
            int r = i + 1;
            while(r < n and abs(v[r] - v[r - 1]) <=2) {
                cur++,r++;
            }
            mn = min(mn, cur);
            mx = max(mx, cur);
        }
        printf("%d %d\n", mn, mx);
    }
    return 0;
}

