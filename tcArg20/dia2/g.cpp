#include <bits/stdc++.h>

using namespace std;

int main() {

    int a,b,k;
    cin >> a >> b >> k;
    
    a = abs(a);
    b = abs(b);
    if(a + b > k) return cout << "No\n", 0;
    if(a + b == k) return cout << "Yes\n", 0;
    if((a + b) % 2 == k % 2) return cout << "Yes\n", 0;
    cout << "No\n";
    return 0;
}

