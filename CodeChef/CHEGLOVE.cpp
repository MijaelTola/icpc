#include <bits/stdc++.h>

using namespace std;

int v[100010];
int g[100010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        for (int i = 0; i < n; ++i) 
            cin >> g[i];

        bool l = 1;
        bool r = 1;
        
        for (int i = 0; i < n; ++i) 
            l &= (g[i] >= v[i]);

        reverse(g, g + n); 
        
        for (int i = 0; i < n; ++i)
            r &= (g[i] >= v[i]);

        if(l and r) cout << "both\n";
        else if(l) cout  << "front\n";
        else if(r) cout << "back\n";
        else cout << "none\n";

    }
    return 0;
}

