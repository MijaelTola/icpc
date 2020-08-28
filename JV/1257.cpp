#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string a,b;
        cin >> a >> b;
        int da = 0, db = 0;
        for (int i = 0; i < (int)a.size(); ++i) 
            if(a[i] != ' ') da += (a[i] - 'a');
        for (int i = 0; i < (int)b.size(); ++i) 
            if(b[i] != ' ') db += (b[i] - 'a');
        if(da == db) cout << "Si\n";
        else cout << "No\n";

    }
    return 0;
}

