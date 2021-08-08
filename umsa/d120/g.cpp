#include <bits/stdc++.h>

using namespace std;

int f(int n) {
 
    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        ans += n % i == 0;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    
    auto get = [&] (long long  x) {
        long long cur = sqrt(x);
        return cur * cur == x;
    };

    while(t--) {
 
        long long a;
        cin >> a;
        
        if(get(a)) cout << "IMPAR\n";
        else cout << "PAR\n";

    }
    return 0;
}


