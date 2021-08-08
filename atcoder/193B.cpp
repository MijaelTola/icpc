#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    int ans = 1e9+10;

    for (int i = 0; i < n; ++i) {
        int a,p,x;
        cin >> a >> p >> x;
        if(x > a) ans = min(ans, p);
    }

    
   

    if(ans == 1e9+10) ans = -1;
    cout << ans << "\n";



   
    return 0;
}

