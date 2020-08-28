#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,a,b,k;
    cin >> n >> a >> b >> k;

    vector<int> v;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int cur = a + b;
        if(x % cur == 0) v.push_back(b / a + (b % a != 0));
        else if(x % cur > a) {
            int d = x % cur;
            d -= a;
            v.push_back(d / a + (d % a != 0));
        } else 
            ans++;
        
    }
    sort(v.begin(), v.end());

    int pos = 0;
    while(pos < (int)v.size() and k >= v[pos] and k >= 0) {
        k -= v[pos];
        pos++;
        ans++;
    }

    cout << ans << "\n";
    return 0;
}

