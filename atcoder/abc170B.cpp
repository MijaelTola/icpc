#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int x,y;
    cin >> x >> y;

    for (int i = 0; i <= x; ++i) {
        int a = i, b = x - i;
        if(2 * a + 4 * b == y) return cout << "Yes\n",0;
    }
    cout << "No\n";

    return 0;
}

