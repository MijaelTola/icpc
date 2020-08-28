#include <bits/stdc++.h>

using namespace std;

vector<long long> v;   
int main(){
    for (int i = 0; i < 31; ++i) {
        for (int j = i + 1; j < 31; ++j) {
            if(i == j) continue;
            long long x = (1 << i);
            long long y = (1 << j);
            v.push_back(x + y);
        }
    }
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int ans = 1e9;
        for (int i = 0; i < (int)v.size(); ++i) {
            int dif = abs(n - v[i]);
            ans = min(ans,dif);
        }
        cout << ans << "\n";
    }
    return 0;
}

