#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main(){
    
    int t; cin >> t;
    while(t--) {
        int n,q;
        cin >> n >> q;
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        while(q--) {
            
            int l,r; cin >> l >> r;
            l--,r--;
            int ans = 0;
            for (int i = l; i <= r ;++i) {
                int andr = v[i];
                for (int j = i; j <= r; ++j) {
                    andr = (andr & v[j]);
                    ans += ((double)sqrt(andr) == (int)sqrt(andr));
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}

