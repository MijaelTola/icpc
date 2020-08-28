#include <bits/stdc++.h>

using namespace std;

int v[1010];
int b[1010];
int main(){
    
    int n; cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    for (int i = 0; i < n; ++i) 
        cin >> b[i];

    int wt = 1e9;
    int w = 1e9;
    int t = 1e9;

    for (int i = 0; i < n; ++i) {
        if(b[i] == 1) t = min(t,v[i]);
        if(b[i] == 2) w = min(w,v[i]);
        if(b[i] == 3) wt = min(wt,v[i]);
    }

    cout << min(wt,w + t) << "\n";
    return 0;
}

