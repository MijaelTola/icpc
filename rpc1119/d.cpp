#include <bits/stdc++.h>

using namespace std;

int main() {

    long double n,k;
    cin >> n >> k;
    
    long double ans = 0;
    for (int i = 0; i < k; ++i) {
        long double su = 0;
        long double sumu = 0;
        long double sd = 0;
        long double sumd = 0;

        for (int j = 1; j <= n; ++j) {
            if(j > ans) {
                su++;
                sumu += j;
            } else {
                sd++;
                sumd += j;
            }
        }

        ans = (sd / n) * ans;
        if(su) ans += (su / n) * (sumu / su); 
    }

    cout.precision(20);
    cout << fixed << ans << "\n";
    return 0;
}

