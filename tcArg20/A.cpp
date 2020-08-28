#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int a,b;
        cin >> a >> b;
        
        int df = abs(a - b);
        if(a > b) {
            if(df % 2 == 0) cout << "1\n";
            else cout << "2\n";
        } else if(a < b) {
            if(df % 2 == 0) cout << "2\n";
            else cout << "1\n";
        } else cout << "0\n";
    }
    return 0;
}

