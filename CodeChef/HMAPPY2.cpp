#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n,a,b,k;
        cin >> n >> a >> b >> k;

        long long da = n / a;
        long long db = n / b;
        long long both = n / ((a * b) / __gcd(a,b));
        da -= both;
        db -= both;
        long long total = da + db;
        if(total >= k)  puts("Win");
        else puts("Lose");
        
    }
    return 0;
}
