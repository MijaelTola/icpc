#include <bits/stdc++.h>

using namespace std;

bool isprime(int x) {
    for (int i = 2; i <= x / 2; ++i) 
        if(x % i == 0) return 0;
    return 1;
}
int main(){
    int t; cin >> t;
    while(t--) {
        int x;
        cin >> x;
        int l = -1;
        for (int i = x - 1; i >= max(x - 300,0); --i) {
            if(isprime(i)) {
                l = i;
                break;
            }
        }
        int r = -1;
        for (int i = x + 1; i <= x + 300; ++i) {
            if(isprime(i)) {
                r = i;
                break;
            }
        }
        
        cout << l + r << "\n";
    }
    
    return 0;
}

