#include <bits/stdc++.h>

using namespace std;

double total(double x, double y) {
    double ans = x * y / 100;
    return ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        double ans = 0;
        for (int i = 0; i < n; ++i) {
            double p,q,d; cin >> p >> q >> d;
            double in = p + total(p,d);
            double t1 = in * d;
            double out = in - total(in,d);
            t1 = p - out;
            t1 *= q;
            ans += t1;

        }
        cout.precision(10);
        cout<<fixed << ans << "\n";
    }
    return 0;
}
    
