#include <bits/stdc++.h>

using namespace std;

int main() {
    

    long long a,b,c;
    cin >> a >> b >> c;
    
    int sa = a > 0 ? 1 : -1;
    int sb = b > 0 ? 1 : -1;
    if(c % 2 == 0) sa = 1, sb = 1;
    
    long double ac = a != 0 ? sa * c * log10(abs(a)) : 0;
    long double bc = b != 0 ? sb * c * log10(abs(b)) : 0;

    if(ac > bc) cout << ">\n";
    if(ac < bc) cout << "<\n";
    if(ac == bc) cout << "=\n";
    return 0;
}

