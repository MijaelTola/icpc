#include <bits/stdc++.h>

using namespace std;

double a,b,c,d;
const double pi = acos(-1);
int main() {
    cin >> a >> b >> c >> d;
    double s = (a + b + c + d) / 2.0;
    double cos2 = (0.5  - 0.5 * cos(2 * pi));
    double ans = sqrt((s - a) * (s - b) * (s - c) * (s - d) 
            - a * b * c * d * cos2);
    cout.precision(15);
    cout<< fixed << ans << "\n";
    return 0;
}

