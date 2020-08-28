#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int a,b,c;
    cin >> a >> b >> c;
    set<int> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);

    if((int)s.size() != 2) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}

