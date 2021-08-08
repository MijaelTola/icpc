#include <bits/stdc++.h>

using namespace std;

//A B C
//A - B + B - C + A - C
//2A - 2C

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<long long> v(n);

        for (auto &x:v )
            cin >> x;
        sort(v.begin(), v.end());

        cout << 2 * v.back() - 2 * v[0] << "\n";
    }
    return 0;
}

