#include <bits/stdc++.h>

using namespace std;

int main(){

    int t; cin >> t;
    while(t--) {
        int m,n;
        cin >> n >> m;
        if(n == 1) return cout << 1 % m << "\n",0;
        if(n == 0) return cout << 0 % m << "\n",0;
        int a = 0;
        int b = 1;
        int c;
        for (int i = 0; i < n - 1; ++i) {
            c = (a + b) % m;
            a = b;
            b = c;
        }
        cout << c << "\n";
    }
    return 0;
}

