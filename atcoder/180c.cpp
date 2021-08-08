#include <bits/stdc++.h>

using namespace std;

int main() {

    long long n;
    cin >> n;
    set<long long> ans;

    for (long long i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ans.insert(n / i);
            ans.insert(i);
        }
    }

    for (auto x: ans)
        cout << x  << "\n";
    return 0;
}

