#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int main() {

    string s;
    cin >> s;
    int sz = s.size();
    int ans = 0;
    int cur = 0;
    for (int i = sz - 1; i >= 0; --i){
        if(s[i] == 'b') cur++;
        else{ ans = (ans+cur)%mod; cur = (2*cur)%mod;}
    }

    cout << ans << "\n";
    return 0;
}

