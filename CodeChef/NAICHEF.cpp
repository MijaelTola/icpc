#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int t; cin >> t;
    while(t--) {
        int n,a,b;
        cin >> n >> a >> b;
        
        int da = 0;
        int db = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if(x == a) da++;
            if(x == b) db++;
        }
        double aa = (double)da / n;
        double bb = (double)db / n;
        
        cout.precision(10);
        cout << fixed << aa * bb << "\n";
    } 
    return 0;
}

