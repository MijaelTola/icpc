#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> b(n);

        for (int &x: v)
            cin >> x;

        for (int &x: b)
            cin >> x;

        sort(v.begin(), v.end());
        sort(b.begin(), b.end());

        long long sum  = 0;
        for (int i = 0; i < n; ++i) 
            sum += min(v[i], b[i]);
        

        cout << sum << "\n";
    }
    return 0;
}

