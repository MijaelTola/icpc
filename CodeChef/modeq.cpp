#include <bits/stdc++.h>

using namespace std;

int aa[1010];
int bb[1010];
int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    
    while(t--) {
        int n,m;
        cin >> n >> m;
        

        long long ans = 0;

        for (int i = 1; i < n; ++i) {
            int a = i, b = n + 1;
            
            while(b - a > 1) {
                int mid = (a + b) >> 1;
                if((m % i) % mid == (m % mid) % i) b = mid;
                else a = mid;
            }
            
            aa[i] = b;
            
            ans += n - min(n,a);
            
        }

        int res = 0;

        for (int i = 1; i < n; ++i) {
            int id = -1;
            for (int j = i + 1; j <= n; ++j)
                if((m % i) % j == (m % j) % i) {
                    cout << i << ": " << j << "\n";
                    res++; 
                    if(id == -1) id = j;
                }
            bb[i] = id;
            
        }

        for (int i = 1; i < n; ++i)
            cout << i<< ": " << aa[i] << " " << bb[i] << " -> " << (aa[i] == bb[i])<< " asdf\n";

        cout << ans << " " << res << "\n";
       
    }

    return 0;
}

