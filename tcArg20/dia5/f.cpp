#include <bits/stdc++.h>

using namespace std;

int main() {

    long long n,x,y,c;
    cin >> n >> x >> y >> c;


    auto ver = [&] (long long k) {
        long long l = max(1LL, x - k);
        long long r = min(n, x + k);

        long long d = max(1LL, y - k);
        long long u = min(n, y + k);

        long long ans = (u - d + 1) + (r - l + 1) - 1;
        
        long long dl = x - l;
        long long dr = r - x;
        long long du = u - y;
        long long dd = y - d;
        
        auto f = [&] (auto x, auto y) {
            
            auto dr = k - 1;
            auto cur = (dr * (dr + 1)) / 2;
            
            auto mx = max(x,y);
            auto df1 = max(0LL, max(0LL, k - x) - 1);
            auto df2 = max(0LL, max(0LL, k - y) - 1);
            
            if(df1 >= mx or df2 >= mx) return x * y;
            cur -= (df1 * (df1 + 1)) / 2;
            cur -= (df2 * (df2 + 1)) / 2;
            return cur;
        };
        
        //cout << dl << " " << du << " " << dr << " " << dd << "\n";
        //cout << f(dr, dd) << "\n";
        //exit(0);
        ans += f(dl, du);
        ans += f(du, dr);
        ans += f(dr, dd);
        ans += f(dd, dl);
        return ans >= c;
    };

    if(n == 1) return cout << "0\n", 0;
    long long a = -1, b = 1e11;

    while(b - a > 1) {
        long long mid = (a + b) / 2;
        if(ver(mid)) b = mid;
        else a = mid;
    }

    cout << b << "\n";
    return 0;
}
