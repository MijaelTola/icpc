#include <bits/stdc++.h>

using namespace std;

int main() {

    int t = 10000;

    cout << t << "\n";
    while(t--) {

        int n = 0, m = 1;
        do {
            n = abs(11 * rand() + rand() + 100)  % 100 + 1;
            m = abs(7 * rand() - rand() + 100) % 100 + 1;
        } while((n * m) % 2 != 0);
        
        assert(n > 0 and m > 0);
        cout << n << " " << m << "\n";

    }
    return 0;
}

