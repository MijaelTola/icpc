#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int w,h,d;
    cin >> w >> h >> d;
    if(h - 2 * d <= 0 or w - 2 * d <= 0) return cout << "0\n",0;
    cout << max((h - 2 * d) * (w - 2 * d) , 0) << "\n";
    return 0;
}

