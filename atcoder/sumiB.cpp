#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    
    int n;
    cin >> n;
 
    for (int i = 1; i <= 5000000; ++i) {
        if((int)i * 1.08 == n) return cout << i << "\n", 0;
    }
    cout << ":(\n";
    return 0;
}
