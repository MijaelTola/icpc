#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    int x = 1000;

    while(x < n) x += 1000;

    cout <<x - n<< "\n";
    return 0;
}

