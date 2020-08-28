#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    if(a < b) return cout << b - a << "\n", 0;

    int cnt = 0;

    auto ver = [&] (int k) {
        int c1 = 1e9;
        int c2 = 1e9;
        int d = (k + 1) / 2;
        if(k & 1) c1 = 1; 
        else c1 = 0;

        c1 += abs(d - b);
        c2 = abs(b - k);
        return c1 < c2;
    };

    while(ver(a)) {
        cnt++;
        cnt += a & 1;
        a = (a + 1) / 2;
    }
    cout << cnt + abs(b - a) << "\n";

    return 0;
}
