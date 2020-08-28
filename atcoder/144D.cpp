#include <bits/stdc++.h>

using namespace std;

const long double pi = acos(-1);
int main() {

    long double a,b,x;
    cin >> a >> b >> x;
    
    long double h1 = b - x / (a * a);
    
    long double a2 = h1 * a / 2.0;
    long double h = a2 / a;
    cout << h << "\n";
    
    printf("%.15Lf\n",atan(a / 2 * (b - h)) * 180 / pi);

    return 0;
}

