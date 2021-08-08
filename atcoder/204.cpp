#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int x,y;
    cin >> x >> y;

    if(x == y) cout << x << "\n";
    else {
        set<int> s = {0, 1,2};
        s.erase(x);
        s.erase(y);
        cout << *s.begin() << "\n";
    }
    return 0;
}

