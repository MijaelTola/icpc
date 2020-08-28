#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int l,r;
    cin >> l >> r;
    if(l == r and l and r) cout << "Even " << l + r << "\n";
    else if(l or r)cout << "Odd " << max(l,r) * 2 << "\n";
    else cout << "Not a moose\n";
    

    return 0;
}

