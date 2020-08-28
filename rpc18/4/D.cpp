#include <bits/stdc++.h>

using namespace std;

int v[370],n;

int f(int pos, int cur, int p) {
    
    int ans = 0;
    for (int i = pos + 1; i < n; ++i) {
        if(cur) ans = max(ans,f(pos + 1, 0)
    }
}
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> v[i];

    return 0;
}

