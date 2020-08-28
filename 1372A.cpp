#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        int x = 1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cout << x << " ";
            cnt++;
            if(cnt == 2) x += 2, cnt = 0;

        }
        cout << "\n";
    }
    return 0;
}

