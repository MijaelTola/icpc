#include <bits/stdc++.h>

using namespace std;

int  v[50010];
int n; 

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) 
            cin >> v[i];
        sort(v, v + n);   
        
        int gcd = v[0];
        
        for (int i = 0; i < n; ++i)
            gcd = __gcd(gcd,v[i]);
        
        if(gcd == 1) cout << 0 << "\n";
        else cout << "-1\n";
    }
        
    return 0;
}

