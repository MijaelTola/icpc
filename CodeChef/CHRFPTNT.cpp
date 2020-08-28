#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n,m,x,k;
        string s;
        cin >> n >> m >> x >> k >> s;
        int even = 0;
        int odd = 0;
        
        for (int i = 0; i < (int)s.size(); ++i) {
            if(s[i] == 'E') even++;
            else odd++;
        }

        int m1 = m / 2; 
        int m2 = m - m1; 
        
        m1 *= x;
        m2 *= x;
        
        int ce = min(m1, even);
        int co = min(m2, odd);
        if(ce + co >= n) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}

