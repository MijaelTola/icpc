#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    long long ans = 0;
    int mul = 1;
    bool f = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        f |= x == 0;
        if(x >= 0) {
            if(x) ans += (x - 1);
            else ans++;
            mul *= 1;
        } else {
            mul *= -1;
            ans += -x - 1;
        }
    }

    if(mul == -1) {
        if(!f)ans += 2;
    }

    cout << ans << "\n";


    return 0;
}

