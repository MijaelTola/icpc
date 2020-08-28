#include <bits/stdc++.h>

using namespace std;

int t,x,k;

int main() {
    
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        
        int cnt = 0;

        while(n % 2 == 0) cnt++,n /= 2;

        for (long long i = 3; i * i <= n; i += 2) {
            while(n % i == 0) cnt++, n /= i;
        }
        if(n > 2) cnt++;
        if(cnt < k) cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}

