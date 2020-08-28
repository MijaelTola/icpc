#include <bits/stdc++.h>

using namespace std;

double v[100010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; 
    cin >> t;
    while(t--) {
        int n; cin >> n;
        int last = 0;
        long double ans = 0;
        for (int i = 0; i < n; ++i) cin >> v[i];
        int c;
        long double d,s; cin >> c >> d >> s;
        long double tm = (long double)(d / s);
    
        long double t1 = 0.0;
        long double t2 = 0.0;
        for (int i = 0; i < n; ++i) {
            t1 += v[i] + tm;
            t2 += v[i] + tm;
            long double cur = v[i] * (c - 1);
            if(t2 < cur + t1) {
                long double dif = (cur + t1) - t2;
                t2 += dif;
            }
            long double diff = t2 - t1;
            t1 = 0.0;
            t2 = diff;
        }
        
        cout.precision(10);
        cout << fixed << t2 << "\n";
    }
    return 0;
}

