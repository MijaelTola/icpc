#include <bits/stdc++.h>

using namespace std;

int main() {

    int x;
    cin >> x;

    if(400 <= x and x <= 599) return cout << "8\n", 0;
    if(600 <= x and x <= 799) return cout << "7\n", 0;
    if(800 <= x and x <= 999) return cout << "6\n", 0;
    if(1000 <= x and x <= 1199) return cout << "5\n", 0;
    if(1200 <= x and x <= 1399) return cout << "4\n", 0;
    if(1400 <= x and x <= 1599) return cout << "3\n", 0;
    if(1600 <= x and x <= 1799) return cout << "2\n", 0;
    if(1800 <= x and x <= 1999) return cout << "1\n", 0;
    return 0;
}

