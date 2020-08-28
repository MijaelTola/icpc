#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string a,b;
    cin >> a >> b;

    a += b.back();

    if(a == b)cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

