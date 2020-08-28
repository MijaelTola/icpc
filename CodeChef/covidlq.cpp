#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int cnt = 100000;;
        bool flag = 1;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(x == 0) cnt++;
            else {
                flag &= cnt >= 5;
                cnt = 0;
            }
        }
        
        cout << (flag ? "YES" : "NO") << "\n";

    }
    return 0;
}

