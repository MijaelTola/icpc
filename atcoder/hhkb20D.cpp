#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,a,b;
        cin >> n >> a >> b;
        if(a < b) swap(a,b);
        
        long long da = (n - a + 1) * (n - a + 1);
        long long db = (n - b + 1) * (n - b + 1);

        long long total = da * db;

        long long cuatro = n - 2 * (b - 1);
        long long tres = n - 2 * (b - 1);
        long long dos = (b - 1);

        cuatro = cuatro * cuatro;
        tres = cuatro * b;
        dos = b * b;

        cout << total << " "  << cuatro * 4 << " " << tres * 3 << " " << dos * 2<< endl;
        long long del = cuatro * 4 + tres * 3 + dos * 2;
        cout << total - del << "\n";
    }
    return 0;
}

