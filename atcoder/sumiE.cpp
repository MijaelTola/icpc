#include <bits/stdc++.h>

using namespace std;

int n;
int c[100010];
int total[4];
const int mod = 1e9 + 7;

int main() {
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c[x]++;
    }
    
    for (int i = 0; i <= 100000; ++i)
        total[c[i]]++;

    long long ans = 1;

    if(total[3]) {
        long long p = 1;
        while(total[3]--) {
            p = (p * 6) % mod;
        }
        ans *= p;
    }
    if(total[2]) ans *= 3 * total[2];
    if(total[1]) ans *= 3;
    cout << ans << "\n";
    return 0;
}

