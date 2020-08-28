#include <bits/stdc++.h>

using namespace std;


long long lcm(long long a, long long b) {
    return a * b / __gcd(a,b);
}
int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        long long mn = n;
        int a1 = 1, a2 = n - 1;
        for (long long i = 1; i * i <= n; ++i) {
            if(n % i == 0) {
                int x = i;
                int y = n - i;
                if(lcm(x,y) < mn and x and y) {
                    mn = lcm(x,y);
                    a1 = x;
                    a2 = y;
                }
                x = n / i;
                y = n - x;

                if(lcm(x,y) < mn and x and y) {
                    mn = lcm(x,y);
                    a1 = x;
                    a2 = y;
                }
            }
        }

        if(n % 2 == 0 and n < mn) {
            a1 = n / 2 , a2 = n / 2;
        }
        cout << a1 << " " << a2 << "\n";
    }
    return 0;
}

