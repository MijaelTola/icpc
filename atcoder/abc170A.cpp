#include <bits/stdc++.h>

using namespace std;

int main() {

    for (int i = 1; i <= 5; ++i) {
        int x;
        cin >> x;
        if(x == 0) return cout << i << "\n", 0;
    }

    return 0;
}

