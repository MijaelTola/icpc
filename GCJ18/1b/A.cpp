#include <bits/stdc++.h>

using namespace std;

int v[100010];

bool ver(int total, int current) {
    double p = current * 100.0 / total;
    double p1 = (int) p + 0.5;
    return p1 >= p;
}

int get(int total, int current) {
    double p = current * 100.0 / total;
    double p1 = (int) p + 0.5;
    if(p1 >= p) return (int) p + 1;
    return p;
}
int main(){
    
    int t; cin >> t;
    for (int k = 1; k <= t; ++k) {
        int n,l; cin >> n >> l;
        int cur = 0;
        for (int i = 0; i < l; ++i)  {
           cin >> v[i]; 
           cur += v[i];
        }
        
        int rest = n - cur;
        int pos = 0;
        int ans = 0;
        while(rest and pos < n) {
            while(!ver(n,v[pos]) and rest) {
                v[pos]++;
                rest--;
            }
            cout << get(n,v[pos]) << "\n";
            ans += get(n,v[pos]);
            pos++;
        }
        
        cout << ans << "\n";

        
    }
    return 0;
}

