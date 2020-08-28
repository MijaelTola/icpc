#include <bits/stdc++.h>

using namespace std;

string a,b; 

bool f(int pos, int bb, int oo) {
    if(pos == 3) return bb == 0 and oo == 0;
    if(bb == 0 and oo == 0) return 1;
    bool ans = false;
    if(a[pos] == 'b' or b[pos] == 'b') ans |= f(pos + 1, bb - 1, oo);
    if(a[pos] == 'o' or b[pos] == 'o') ans |= f(pos + 1, bb, oo - 1);
    return ans;
}
int main(){
    
    int t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << (f(0,2,1) ? "yes": "no") << "\n";
    }
    return 0;
}

