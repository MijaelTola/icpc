#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n, y;
        cin >> n >> y;
        vector<long long> v(n);

        long long sum = 0;

        for (long long &x: v) {
            cin >> x;
            sum += x;
        }

        sort(v.begin(), v.end());
        int cur = n;
        int pos = 0;
        while(pos < n and cur and sum / cur < y) {
            sum -= v[pos];
            pos++;
            cur--;
        }
       
        cout << n - pos << "\n";

    }




    return 0;
}

