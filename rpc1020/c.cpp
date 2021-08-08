#include <bits/stdc++.h>

using namespace std;

bool m[50000][100];

int main() {
    memset(m, 0, sizeof m);
    int bb,r;
    cin >> bb >> r;


    auto check = [&](int altura, int ini, int x, int y) {
        bool flag = 1;
        for (int i = altura; i <= altura + y - 1; ++i) {
            for (int j = ini; j <= min(bb, ini + x - 1); ++j) {
                flag &= !m[i][j];
            }
        }	
        return flag;
    };

    auto fill = [&](int altura, int ini, int x, int y) {
        bool flag = 1;
        for (int i = 0; i <= altura + y - 1; ++i) {
            for (int j = ini; j <= min(bb, ini + x - 1); ++j) {
                m[i][j] = 1;
            }
        }	
        return flag;
    };

    int ans = 0;
    while(r--) {
        int h,w,p;
        cin >> h >> w >> p;

        int a = 0, b = 10000;

        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(check(mid, p, h, w)) b = mid;
            else a = mid;
        }
        
        fill(b, p, h, w);
    
        ans = max(ans, b + w - 1);
    }

    cout << ans  << "\n";
    return 0;
}
