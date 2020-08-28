#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n1,n2;
    cin >> n1 >> n2;
        
    if(n1 < n2) {
        int d = n2 - n1;
        int d2 = 360 - d;
        if(d <= d2) cout << d << "\n";
        else cout << -d2 << "\n";
    } else {
        int d = n1 - n2;
        int d2 = 360 - d;
        if(d < d2) cout << -d << "\n";
        else cout << d2 << "\n";
    }
    return 0;
}

