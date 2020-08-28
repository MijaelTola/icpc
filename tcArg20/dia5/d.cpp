#include <bits/stdc++.h>

using namespace std;

int main() {
    int h,m;

    scanf("%d:%d", &h, &m);
    
    h %= 12;
    double all = 360;
    double hr = all / 12;
    double mn = all / 60;
    
    double x = (100 * m / 60.) / 100;

    double ans1 = hr * h;
    double ang = hr * x;
    cout << ans1 + ang << " " << mn * m << "\n";
    return 0;
}

