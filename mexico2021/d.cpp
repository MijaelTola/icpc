#include <bits/stdc++.h>

using namespace std;

int main() {


    auto f = [&] (int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            ans += (1 << i);
        return ans;
    };

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        cout << f(n) << "\n";

        
    }
    return 0;
}

