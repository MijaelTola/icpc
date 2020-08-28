#include <bits/stdc++.h>

using namespace std;

int main() {
    
    set<int> s;
    int x,n;
    cin >> x >> n;

    for (int i = -200; i <= 200; ++i)
        s.insert(i);

    for (int i = 0; i < n; ++i) {
        int z;
        cin >> z;
        s.erase(z);
    }

    auto p = s.lower_bound(x);

    auto p2 = p;
    if(s.begin() != p2) p2--;

    if(abs(*p - x) < abs(*p2 - x)) cout << *p << "\n";
    else cout << *p2 << "\n";
    return 0;
}

