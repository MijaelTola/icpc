#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,l,r;
        cin >> n >> l >> r;

        int ini = 2 * (l / 2);
        int val = ini + 1;
        int cur = ini - (l & 1);
        cout << ini << " test\n";
        while(l <= r) {
            if(cur >= n) break;
            if(cur != val) {
                cout << 1 << " ";
                cur = val;
            } else {
                cout << val << " ";
                cur = 1;
                val++;
            }
            l++;
        }
        
        int c = -1;
        while(l <= r) {
            cout << cur << " ";   
            cur += c;
            if(cur == 2) c = 1;
            l++;
        }
        cout << "\n";
        
    }
    return 0;
}

