#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    while(t--) {

        int x,y;
        cin >> x >> y;
        
        if(x > y) swap(x,y);
        if((x + y) % 3 == 0 && 2 * x >= y) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

