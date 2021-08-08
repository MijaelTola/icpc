#include <bits/stdc++.h>

using namespace std;

int main() {
    
    auto sum = [&](int x) {
        int ans = 0;

        while(x > 0) {
            ans += x % 10;
            x /= 10;
        };
        return ans;
    };

    int a,b;
    cin >> a >> b;

    cout  << max(sum(a), sum(b)) << "\n";
    return 0;
}

