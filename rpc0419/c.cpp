#include <bits/stdc++.h>

using namespace std;

int n;
int main() {
    cin >> n;
    int ans = 1e9;
    vector<int> dv;
    for (int i = 1; i <= n; ++i) 
        if(n % i == 0) dv.push_back(i);

    for (auto i: dv)
        for (auto j: dv)
            for (auto k: dv) {
                if(i * j * k == n) {

                    ans = min(ans, i * j + j * k + i * k);
                }
            }
    cout << 2 * ans << "\n";
    return 0;
}

