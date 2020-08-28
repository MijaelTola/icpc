#include <bits/stdc++.h>

using namespace std;


double pi = acos(-1);

int main() {
    double a1, p1, r1, p2;
    cin >> a1 >> p1 >> r1 >> p2;

    double a2 = pi * (r1 * r1);
    
    double d = 1000;

    double d1 = d / p1;
    double d2 = d / p2;

    if(d1 * a1 > d2 * a2) puts("Slice of pizza");
    else puts("Whole pizza");
    return 0;
}

